#ifndef FFTW_PLAN_H
#define FFTW_PLAN_H

#include <concepts>

#include "fftw3.h"
#include "fftw_data_support.h"

namespace fftw
{
	 enum class direction :int
	{
		forward  = FFTW_FORWARD,
		backward = FFTW_BACKWARD
	};

	 using r2r_kind = ::fftw_r2r_kind_do_not_use_me;

	 enum optimization : unsigned int
	{
		measure         = FFTW_MEASURE,
		destroy_input   = FFTW_DESTROY_INPUT,
		unaligned       = FFTW_UNALIGNED,
		conserve_memory = FFTW_CONSERVE_MEMORY,
		exhaustive      = FFTW_EXHAUSTIVE,
		preserve_input  = FFTW_PRESERVE_INPUT,
		patient         = FFTW_PATIENT,
		estimate        = FFTW_ESTIMATE,
		wisdom_only     = FFTW_WISDOM_ONLY
	};

	template <typename T, typename ...U>
	concept pack_is = sizeof...(U) == 1 &&
		std::same_as<T, typename std::tuple_element<0, std::tuple<U...>>::type>;

	template <typename T, typename U, typename... option_t>
	concept valid_c2c = !std::floating_point<T> && !std::floating_point<U> && pack_is<direction, option_t...>;

	template <typename T, typename U, typename... option_t>
	concept valid_r2r = std::floating_point<T> && std::floating_point<U> && 
		(pack_is<const r2r_kind*, option_t...> || pack_is<r2r_kind*, option_t...>);

	template <typename T, typename U, typename... option_t>
	concept valid_r2c = std::floating_point<T> && !std::floating_point<U> && sizeof...(option_t) == 0;

	template <typename T, typename U, typename... option_t>
	concept valid_c2r = !std::floating_point<T> && std::floating_point<U> && sizeof...(option_t) == 0;

	template <typename T, typename U>
	concept valid_io_types =
		supported_type<T> && supported_type<U> &&
		std::same_as<typename primitive<T>::type, typename primitive<U>::type>;

	template <typename T, typename U, typename... option_t>
	concept valid_option = 
		valid_c2c<T, U, option_t...> || 
		valid_r2r<T, U, option_t...> || 
		valid_r2c<T, U, option_t...> || 
		valid_c2r<T, U, option_t...>;

	template <typename T, typename U>
	concept contiguous_of = requires (const T& container)
	{
		{ container.size() } -> std::integral;
		{ container.data() } -> std::same_as<const U*>;
	};

	template <typename... option_t>
	static auto get_opt(const option_t& ...option)
	{
		return std::get<0>(std::tie(option...));
	}

	 using guru_params = fftw_iodim64_do_not_use_me;

	 namespace split
	{
		struct r2c {};
		struct c2r {};
	}

	 template <typename input_t, typename output_t, bool split = false>
	class plan
	{
		using primitive_type = primitive<input_t>::type;
		using plan_impl_type = std::remove_pointer_t<
			std::conditional_t<std::is_same_v<primitive_type, float>, ::fftwf_plan,
			std::conditional_t<std::is_same_v<primitive_type, double>, ::fftw_plan,
			/*long double*/ ::fftwl_plan>>>;
		template <typename T>
		using raw_type = std::conditional_t<std::is_same_v<T, primitive_type>,
			primitive_type,
			primitive_type[2]>;

		std::shared_ptr<plan_impl_type> plan_impl;

		void set_impl(plan_impl_type* raw_impl_ptr)
		{
			if (!raw_impl_ptr)
				throw std::domain_error("FFTW3 cannot create plan, check input.");

			plan_impl.reset(raw_impl_ptr,
				[](plan_impl_type* p)
				{
					select_fftw_func<primitive_type>(
						::fftwf_destroy_plan, ::fftw_destroy_plan, ::fftwl_destroy_plan)(p);
				}
			);
		}

		template<typename T>
		static auto raw_cast(T* p)
		{
			return reinterpret_cast<raw_type<T>*>(p);
		}

	public:
		// Advanced Interface
		template <typename extent_t, typename... option_t>
			requires valid_io_types<input_t, output_t>&& valid_option<input_t, output_t, option_t...>&& contiguous_of<extent_t, int>
		plan(const extent_t& extent,
			const int& num_batches,
			input_t* input,
			const int* inembed,
			const int& input_stride,
			const int& input_dist,
			output_t* output,
			const int* onembed,
			const int& output_stride,
			const int& output_dist,
			const unsigned int& optimization,
			const option_t& ...option)
		{
			auto rank = static_cast<int>(extent.size());
			auto dims = extent.data();
			auto raw_input_ptr = this->raw_cast(input);
			auto raw_output_ptr = this->raw_cast(output);
			plan_impl_type* raw_impl_ptr = nullptr;

			if constexpr (valid_c2c<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_many_dft, ::fftw_plan_many_dft, ::fftwl_plan_many_dft)(
					rank, dims, num_batches,
					raw_input_ptr, inembed, input_stride, input_dist,
					raw_output_ptr, onembed, output_stride, output_dist,
					static_cast<int>(get_opt(option...)), optimization);
			if constexpr (valid_r2r<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_many_r2r, ::fftw_plan_many_r2r, ::fftwl_plan_many_r2r)(
					rank, dims, num_batches,
					raw_input_ptr, inembed, input_stride, input_dist,
					raw_output_ptr, onembed, output_stride, output_dist,
					get_opt(option...), optimization);
			if constexpr (valid_r2c<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_many_dft_r2c, ::fftw_plan_many_dft_r2c, ::fftwl_plan_many_dft_r2c)(
					rank, dims, num_batches,
					raw_input_ptr, inembed, input_stride, input_dist,
					raw_output_ptr, onembed, output_stride, output_dist,
					optimization);
			if constexpr (valid_c2r<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_many_dft_c2r, ::fftw_plan_many_dft_c2r, ::fftwl_plan_many_dft_c2r)(
					rank, dims, num_batches,
					raw_input_ptr, inembed, input_stride, input_dist,
					raw_output_ptr, onembed, output_stride, output_dist,
					optimization);

			this->set_impl(raw_impl_ptr);
		}

		// Basic Interface
		template <typename extent_t, typename... option_t>
			requires valid_io_types<input_t, output_t>&& valid_option<input_t, output_t, option_t...>&& contiguous_of<extent_t, int>
		plan(const extent_t& extent, input_t* input, output_t* output, const unsigned int& optimization, const option_t& ...option) :
			plan(extent, 1, input, nullptr, 1, 1, output, nullptr, 1, 1, optimization, option...) {}

		// Guru Interface
		template <typename rank_extent_t, typename batch_extent_t, typename... option_t>
			requires valid_io_types<input_t, output_t> && valid_option<input_t, output_t, option_t...>&&
		contiguous_of<rank_extent_t, guru_params> && contiguous_of<batch_extent_t, guru_params>
			plan(const rank_extent_t& rank_extent, const batch_extent_t& batch_extent,
				input_t* input, output_t* output,
				const unsigned int& optimization, const option_t& ...option)
		{
			auto rank = static_cast<int>(rank_extent.size());
			auto dims = rank_extent.data();
			auto batch_rank = static_cast<int>(batch_extent.size());
			auto batch_params = batch_extent.data();
			auto raw_input_ptr = this->raw_cast(input);
			auto raw_output_ptr = this->raw_cast(output);
			plan_impl_type* raw_impl_ptr = nullptr;

			if constexpr (valid_c2c<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_guru64_dft, ::fftw_plan_guru64_dft, ::fftwl_plan_guru64_dft)(
					rank, dims, batch_rank, batch_params,
					raw_input_ptr, raw_output_ptr,
					static_cast<int>(get_opt(option...)), optimization);
			if constexpr (valid_r2r<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_guru64_r2r, ::fftw_plan_guru64_r2r, ::fftwl_plan_guru64_r2r)(
					rank, dims, batch_rank, batch_params,
					raw_input_ptr, raw_output_ptr,
					get_opt(option...), optimization);
			if constexpr (valid_r2c<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_guru64_dft_r2c, ::fftw_plan_guru64_dft_r2c, ::fftwl_plan_guru64_dft_r2c)(
					rank, dims, batch_rank, batch_params,
					raw_input_ptr, raw_output_ptr,
					optimization);
			if constexpr (valid_c2r<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_guru64_dft_c2r, ::fftw_plan_guru64_dft_c2r, ::fftwl_plan_guru64_dft_c2r)(
					rank, dims, batch_rank, batch_params,
					raw_input_ptr, raw_output_ptr,
					optimization);

			this->set_impl(raw_impl_ptr);
		}

		// Guru Split C2C
		template <typename rank_extent_t, typename batch_extent_t, supported_fp_type fp_type>
			requires valid_c2c<input_t, output_t, direction>
		plan(const rank_extent_t& rank_extent, const batch_extent_t& batch_extent,
			fp_type* input_real, fp_type* input_imag, fp_type* output_real, fp_type* output_iamg,
			const unsigned int& optimization)
		{

			auto rank = static_cast<int>(rank_extent.size());
			auto dims = rank_extent.data();
			auto batch_rank = static_cast<int>(batch_extent.size());
			auto batch_params = batch_extent.data();

			this->set_impl(
				select_fftw_func<primitive_type>(::fftwf_plan_guru64_split_dft, ::fftw_plan_guru64_split_dft, ::fftwl_plan_guru64_split_dft)(
					rank, dims, batch_rank, batch_params,
					input_real, input_imag, output_real, output_iamg,
					optimization)
			);
		}

		// Guru Split C2R
		template <typename rank_extent_t, typename batch_extent_t, supported_fp_type fp_type>
			requires valid_c2r<input_t, output_t>
		plan(const split::c2r&, const rank_extent_t& rank_extent, const batch_extent_t& batch_extent,
			fp_type* input_real, fp_type* input_imag, fp_type* output_real,
			const unsigned int& optimization)
		{

			auto rank = static_cast<int>(rank_extent.size());
			auto dims = rank_extent.data();
			auto batch_rank = static_cast<int>(batch_extent.size());
			auto batch_params = batch_extent.data();

			this->set_impl(
				select_fftw_func<primitive_type>(::fftwf_plan_guru64_split_dft_c2r, ::fftw_plan_guru64_split_dft_c2r, ::fftwl_plan_guru64_split_dft_c2r)(
					rank, dims, batch_rank, batch_params,
					input_real, input_imag, output_real,
					optimization)
			);
		}

		// Guru Split R2C
		template <typename rank_extent_t, typename batch_extent_t, supported_fp_type fp_type>
			requires valid_r2c<input_t, output_t>
		plan(const split::r2c&, const rank_extent_t& rank_extent, const batch_extent_t& batch_extent,
			fp_type* input_real, fp_type* output_real, fp_type* output_imag,
			const unsigned int& optimization)
		{

			auto rank = static_cast<int>(rank_extent.size());
			auto dims = rank_extent.data();
			auto batch_rank = static_cast<int>(batch_extent.size());
			auto batch_params = batch_extent.data();

			this->set_impl(
				select_fftw_func<primitive_type>(::fftwf_plan_guru64_split_dft_r2c, ::fftw_plan_guru64_split_dft_r2c, ::fftwl_plan_guru64_split_dft_r2c)(
					rank, dims, batch_rank, batch_params,
					input_real, output_real, output_imag,
					optimization)
			);
		}

		plan(const plan&) = default;
		plan(plan&&) = default;
		plan& operator=(const plan& other) = default;
		plan& operator=(plan&&) = default;

		plan() = delete;

		void execute()
		{
			select_fftw_func<primitive_type>(::fftwf_execute, ::fftw_execute, ::fftwl_execute)(plan_impl.get());
		}

		void execute(input_t* input, output_t* output)
			requires (!split)
		{
			auto raw_input_ptr = raw_cast(input);
			auto raw_output_ptr = raw_cast(output);

			if constexpr (valid_c2c<input_t, output_t, direction>)
				select_fftw_func<primitive_type>(::fftwf_execute_dft, ::fftw_execute_dft, ::fftwl_execute_dft)(
					plan_impl.get(), raw_input_ptr, raw_output_ptr);
			if constexpr (valid_r2r<input_t, output_t, const r2r_kind*>)
				select_fftw_func<primitive_type>(::fftwf_execute_r2r, ::fftw_execute_r2r, ::fftwl_execute_r2r)(
					plan_impl.get(), raw_input_ptr, raw_output_ptr);
			if constexpr (valid_r2c<input_t, output_t>)
				select_fftw_func<primitive_type>(::fftwf_execute_dft_r2c, ::fftw_execute_dft_r2c, ::fftwl_execute_dft_r2c)(
					plan_impl.get(), raw_input_ptr, raw_output_ptr);
			if constexpr (valid_c2r<input_t, output_t>)
				select_fftw_func<primitive_type>(::fftwf_execute_dft_c2r, ::fftw_execute_dft_c2r, ::fftwl_execute_dft_c2r)(
					plan_impl.get(), raw_input_ptr, raw_output_ptr);
		}

		void execute(primitive_type* input_real, primitive_type* input_imag, primitive_type* output_real, primitive_type* output_imag)
			requires valid_c2c<input_t, output_t, direction> && split
		{
			select_fftw_func<primitive_type>(::fftwf_execute_split_dft, ::fftw_execute_split_dft, ::fftwl_execute_split_dft)(
				plan_impl.get(), input_real, input_imag, output_real, output_imag);
		}

		void execute(primitive_type* input_real, primitive_type* output_real, primitive_type* output_imag)
			requires valid_r2c<input_t, output_t> && split
		{
			select_fftw_func<primitive_type>(
				::fftwf_execute_split_dft_r2c, ::fftw_execute_split_dft_r2c, ::fftwl_execute_split_dft_r2c)(
					plan_impl.get(), input_real, output_real, output_imag);
		}

		void execute(primitive_type* input_real, primitive_type* input_imag, primitive_type* output_real)
			requires valid_c2r<input_t, output_t> && split
		{
			select_fftw_func<primitive_type>(
				::fftwf_execute_split_dft_c2r, ::fftw_execute_split_dft_c2r, ::fftwl_execute_split_dft_c2r)(
					plan_impl.get(), input_real, input_imag, output_real);
		}
	};

	template <typename rank_extent_t, typename batch_extent_t, supported_fp_type fp_type>
	plan(const rank_extent_t&, const batch_extent_t&, fp_type*, fp_type*, fp_type*, fp_type*, const unsigned int&)
		-> plan<std::complex<fp_type>, std::complex<fp_type>, true>;

	template <typename rank_extent_t, typename batch_extent_t, supported_fp_type fp_type>
	plan(const split::c2r&, const rank_extent_t&, const batch_extent_t&, fp_type*, fp_type*, fp_type*, const unsigned int&)
		-> plan<std::complex<fp_type>, fp_type, true>;

	template <typename rank_extent_t, typename batch_extent_t, supported_fp_type fp_type>
	plan(const split::r2c&, const rank_extent_t&, const batch_extent_t&, fp_type*, fp_type*, fp_type*, const unsigned int&)
		-> plan<fp_type, std::complex<fp_type>, true>;
}

#endif