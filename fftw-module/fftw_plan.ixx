export module fftw_plan;

import <fftw3.h>;
import std;
import fftw_data_support;
import fftw_vector;


namespace fftw
{
	export enum class direction :int
	{
		forward  = FFTW_FORWARD,
		backward = FFTW_BACKWARD
	};

	export using r2r_kind = ::fftw_r2r_kind_do_not_use_me;

	export enum optimization : unsigned int
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
	concept pack_is = requires { requires std::same_as<T, U...>; };

	template <typename T, typename U, typename... option_t>
	concept valid_c2c = !std::floating_point<T> && !std::floating_point<U> && pack_is<direction, option_t...>;

	template <typename T, typename U, typename... option_t>
	concept valid_r2r = std::floating_point<T> && std::floating_point<U> && pack_is<const r2r_kind*, option_t...>;

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

	export using guru_params = fftw_iodim64_do_not_use_me;

	namespace split
	{
		struct r2c {};
		struct c2r {};
	}

	template <typename input_t, typename output_t>
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

		template <typename extent_t, typename... option_t>
			requires valid_io_types<input_t, output_t>&& valid_option<input_t, output_t, option_t...>&& contiguous_of<extent_t, int>
		plan(const extent_t& extent,
			const int& num_batches,
			input_t* input,
			const int* inembed,
			const int& input_stride,
			const int& input_batch_offset,
			output_t* output,
			const int* onembed,
			const int& output_stride,
			const int& output_batch_offset,
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
					raw_input_ptr, inembed, input_stride, input_batch_offset,
					raw_output_ptr, onembed, output_stride, output_batch_offset,
					static_cast<int>(get_opt(option...)), optimization);
			if constexpr (valid_r2r<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_many_r2r, ::fftw_plan_many_r2r, ::fftwl_plan_many_r2r)(
					rank, dims, num_batches,
					raw_input_ptr, inembed, input_stride, input_batch_offset,
					raw_output_ptr, onembed, output_stride, output_batch_offset,
					get_opt(option...), optimization);
			if constexpr (valid_r2c<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_many_dft_r2c, ::fftw_plan_many_dft_r2c, ::fftwl_plan_many_dft_r2c)(
					rank, dims, num_batches,
					raw_input_ptr, inembed, input_stride, input_batch_offset,
					raw_output_ptr, onembed, output_stride, output_batch_offset,
					optimization);
			if constexpr (valid_c2r<input_t, output_t, option_t...>)
				raw_impl_ptr = select_fftw_func<primitive_type>(::fftwf_plan_many_dft_c2r, ::fftw_plan_many_dft_c2r, ::fftwl_plan_many_dft_c2r)(
					rank, dims, num_batches,
					raw_input_ptr, inembed, input_stride, input_batch_offset,
					raw_output_ptr, onembed, output_stride, output_batch_offset,
					optimization);

			this->set_impl(raw_impl_ptr);
		}

		template <typename extent_t, typename... option_t>
			requires valid_io_types<input_t, output_t>&& valid_option<input_t, output_t, option_t...>&& contiguous_of<extent_t, int>
		plan(const extent_t& extent, input_t* input, output_t* output, const unsigned int& optimization, const option_t& ...option) :
			plan(extent, 1, input, nullptr, 1, 1, output, nullptr, 1, 1, optimization, option...) {}

		template <typename rank_extent_t, typename batch_extent_t, typename... option_t>
			requires valid_io_types<input_t, output_t>&& valid_option<input_t, output_t, option_t...>&&
		contiguous_of<rank_extent_t, guru_params>&& contiguous_of<batch_extent_t, guru_params>
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
			requires valid_c2c<input_t, output_t, direction>
		{
			select_fftw_func<primitive_type>(::fftwf_execute_split_dft, ::fftw_execute_split_dft, ::fftwl_execute_split_dft)(
				plan_impl.get(), input_real, input_imag, output_real, output_imag);
		}

		void execute(primitive_type* input_real, primitive_type* output_real, primitive_type* output_imag)
			requires valid_r2c<input_t, output_t>
		{
			select_fftw_func<primitive_type>(
				::fftwf_execute_split_dft_r2c, ::fftw_execute_split_dft_r2c, ::fftwl_execute_split_dft_r2c)(
					plan_impl.get(), input_real, output_real, output_imag);
		}

		void execute(primitive_type* input_real, primitive_type* input_imag, primitive_type* output_real)
			requires valid_c2r<input_t, output_t>
		{
			select_fftw_func<primitive_type>(
				::fftwf_execute_split_dft_c2r, ::fftw_execute_split_dft_c2r, ::fftwl_execute_split_dft_c2r)(
					plan_impl.get(), input_real, input_imag, output_real);
		}
	};

	template <typename rank_extent_t, typename batch_extent_t, supported_fp_type fp_type>
	plan(const rank_extent_t&, const batch_extent_t&, fp_type*, fp_type*, fp_type*, fp_type*, const unsigned int&)
		-> plan<std::complex<fp_type>, std::complex<fp_type>>;

	template <typename rank_extent_t, typename batch_extent_t, supported_fp_type fp_type>
	plan(const split::c2r&, const rank_extent_t&, const batch_extent_t&, fp_type*, fp_type*, fp_type*, const unsigned int&)
		-> plan<std::complex<fp_type>, fp_type>;

	template <typename rank_extent_t, typename batch_extent_t, supported_fp_type fp_type>
	plan(const split::r2c&, const rank_extent_t&, const batch_extent_t&, fp_type*, fp_type*, fp_type*, const unsigned int&)
		-> plan<fp_type, std::complex<fp_type>>;

	void func()
	{
		vector<double> v(32);

		//using namespace std::complex_literals;
		//test_func(1.0, 1.0);
		//test_func(1.0, 1.0+1i);
		//test_func(1.0 + 1i, 1.0);
		//test_func(1.0 + 1i, 1.0 + 1i);

		std::vector<double> v1;
		std::vector<std::complex<double>> v2;
		std::vector<std::complex<double>> v3;
		std::array<int, 3> a3;
		plan pl_c2c(a3, 1, v3.data(), nullptr, 1, 1, v2.data(), nullptr, 1, 1,
			optimization::measure | optimization::conserve_memory, direction::forward);
		plan pl_c2c1(a3, v3.data(), v2.data(),
			optimization::measure | optimization::conserve_memory, direction::forward);
		pl_c2c.execute(v3.data(), v2.data());
		pl_c2c.execute();
		pl_c2c.execute(v1.data(), v1.data(), v1.data(), v1.data());
		//pl_c2c1.execute(v3.data(), v2.data());
		//pl_c2c1.execute();

		const auto kp = r2r_kind::FFTW_HC2R;
		plan pl_r2r(a3, 1, v1.data(), nullptr, 1, 1, v1.data(), nullptr, 1, 1,
			optimization::measure | optimization::conserve_memory, &kp);
		plan pl_r2r1(a3, v1.data(), v1.data(),
			optimization::measure | optimization::conserve_memory, &kp);
		plan pl_r2c(a3, 1, v1.data(), nullptr, 1, 1, v2.data(), nullptr, 1, 1,
			optimization::measure | optimization::conserve_memory);
		plan pl_r2c1(a3, v1.data(), v2.data(),
			optimization::measure | optimization::conserve_memory);
		pl_r2c.execute(v1.data(), v1.data(), v1.data());
		plan pl_c2r(a3, 1, v2.data(), nullptr, 1, 1, v1.data(), nullptr, 1, 1,
			optimization::measure | optimization::conserve_memory);
		plan pl_c2r1(a3, v2.data(), v1.data(),
			optimization::measure | optimization::conserve_memory);
		pl_c2r.execute(v1.data(), v1.data(), v1.data());

		//static_assert(valid_io_types<float, float>);
		//static_assert(valid_io_types<float, float, r2r_kind>);
		//static_assert(valid_io_types<float, float, direction>);

		//static_assert(valid_io_types<float, std::complex<float>, r2r_kind>);
		//static_assert(valid_io_types<float, std::complex<float>, direction>);
		//static_assert(valid_io_types<float, std::complex<float>>);

		//static_assert(valid_io_types<std::complex<float>, std::complex<float>, r2r_kind>);
		//static_assert(valid_io_types<std::complex<float>, std::complex<float>, direction>);
		//static_assert(valid_io_types<std::complex<float>, std::complex<float>>);

		std::vector<guru_params> gp1, gp2;

		plan gplc2c(gp1, gp2, v3.data(), v3.data(), optimization::measure | optimization::conserve_memory, direction::forward);
		plan gplr2r(gp1, gp2, v1.data(), v1.data(), optimization::measure | optimization::conserve_memory, &kp);
		plan gplc2r(gp1, gp2, v2.data(), v1.data(), optimization::measure | optimization::conserve_memory);
		plan gplr2c(gp1, gp2, v1.data(), v2.data(), optimization::measure | optimization::conserve_memory);
		plan gplc2cs(gp1, gp2, v1.data(), v1.data(), v1.data(), v1.data(), optimization::measure | optimization::conserve_memory);
		plan gplc2rs(split::c2r{}, gp1, gp2, v1.data(), v1.data(), v1.data(), optimization::measure | optimization::conserve_memory);
		plan gplr2cs(split::r2c{}, gp1, gp2, v1.data(), v1.data(), v1.data(), optimization::measure | optimization::conserve_memory);
	}
}