export module fftw_data_support;

import std;

namespace fftw
{
	export template <typename T>
	struct primitive : std::type_identity<T> {};

	export template <typename T>
	struct primitive<std::complex<T>> : std::type_identity<T> {};

	template <typename T, typename... fftw3_data_types>
	concept is_fftw3_type = (std::same_as<typename primitive<T>::type, fftw3_data_types> || ...);

	export template <typename T>
	concept supported_type = is_fftw3_type<T,
		float,
		double,
		long double
	>;

	export template <typename T>
	concept supported_fp_type = std::same_as<T, float> || std::same_as<T, double> || std::same_as<T, long double>;

	// Select the corresponding fftw functions based on precision
	export template <supported_fp_type T>
	auto select_fftw_func(auto float_func, auto double_func, auto long_double_func)
	{

		if constexpr (std::is_same_v<T, float>)
			return float_func;
		if constexpr (std::is_same_v<T, double>)
			return double_func;
		if constexpr (std::is_same_v<T, long double>)
			return long_double_func;
		std::unreachable();
	}
}