#ifndef FFTW_DATA_SUPPORT_H
#define FFTW_DATA_SUPPORT_H

#include <complex>
#include <utility>

namespace fftw
{
	template <typename T>
	struct primitive : std::type_identity<T> {};

	template <typename T>
	struct primitive<std::complex<T>> : std::type_identity<T> {};

	template <typename T, typename... fftw3_data_types>
	concept is_fftw3_type = (std::same_as<typename primitive<T>::type, fftw3_data_types> || ...);

	// The data types supported for FFTW3 inputs and outputs
	template <typename T>
	concept supported_type = is_fftw3_type<T,
		float,
		double,
		long double
	>;

	// The floating point types supported in FFTW3
	template <typename T>
	concept supported_fp_type = std::same_as<T, float> || std::same_as<T, double> || std::same_as<T, long double>;

	// Select the corresponding fftw functions based on the floating point type
	template <supported_fp_type T>
	auto select_fftw_func(auto float_func, auto double_func, auto long_double_func)
	{
		if constexpr (std::is_same_v<T, float>)
			return float_func;
		else if constexpr (std::is_same_v<T, double>)
			return double_func;
		else /* long double */
			return long_double_func;
	}
}

#endif