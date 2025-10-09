#ifndef FFTW_VECTOR_H
#define FFTW_VECTOR_H

#include <vector>

#include "fftw3.h"
#include "fftw_data_support.h"

namespace fftw
{
	template<typename T>
	struct allocator
	{
		using value_type = T;
		using primitive_type = primitive_t<T>;

		allocator() = default;

		template <class U> allocator(allocator<U> const&) noexcept {}

		value_type* allocate(std::size_t n)
		{
			const auto bytes = n * sizeof(value_type);
			if constexpr (supported_type<value_type>)
				return static_cast<value_type*>(
					select_fftw_func<primitive_type>(::fftwf_malloc, ::fftw_malloc, ::fftwl_malloc)(bytes));
			else
				return static_cast<value_type*>(::operator new(bytes));
		}

		void deallocate(value_type* p, std::size_t) noexcept  
		{
			if constexpr (supported_type<value_type>)
				select_fftw_func<primitive_type>(::fftwf_free, ::fftw_free, ::fftwl_free)(p);
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

	template<supported_type T>
	using vector = std::vector<T, allocator<T>>;
}

#endif