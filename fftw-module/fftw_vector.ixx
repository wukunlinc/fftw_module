export module fftw_vector;

import "fftw3.h";
import std;
import fftw_data_support;


namespace fftw
{
	template<typename T>
	struct allocator
	{
		using value_type = T;

		allocator() = default;

		template <class U> allocator(allocator<U> const&) noexcept {}

		value_type* allocate(std::size_t n)
		{
			const auto bytes = n * sizeof(value_type);
			if constexpr (supported_type<value_type>)
				return static_cast<value_type*>(
					select_fftw_func<value_type>(::fftwf_malloc, ::fftw_malloc, ::fftwl_malloc)(bytes));
			else
				return static_cast<value_type*>(::operator new(bytes));
		}

		void deallocate(value_type* p, std::size_t) noexcept  
		{
			if constexpr (supported_type<value_type>)
				select_fftw_func<value_type>(::fftwf_free, ::fftw_free, ::fftwl_free)(p);
			else
				::operator delete(p);
		}
	};

	template <typename T, typename U>
	bool operator==(allocator<T> const&, allocator<U> const&) noexcept
	{
		return true;
	}

	template <typename T, typename U>
	bool operator!=(allocator<T> const& x, allocator<U> const& y) noexcept
	{
		return !(x == y);
	}

	export template<supported_type T>
	using vector = std::vector<T, allocator<T>>;
}