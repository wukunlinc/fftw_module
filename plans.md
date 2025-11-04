The following table shows how each FFTW3 plan creation functions are called. 

Notes: 
- `double` is used as example, `float` and `long double` are also supported
- input `array` can be replaced by `vector` or any contiguous container with `size()` and `data()` member functions
- the first 4 constructors mimic the basic interface, i.e. the stride and dist are filled with 1's

| FFTW3 function | Wrapper code  |
| ----------- | ----------- |
| `fftw_plan_many_dft` | `fftw::plan(std::array<int, N>, std::complex<double>*,  std::complex<double>*, unsigned int, fftw::direction)` |
| `fftw_plan_many_dft_c2r` | `fftw::plan(std::array<int, N>, std::complex<double>*,  double*, unsigned int)` |
| `fftw_plan_many_dft_r2c` | `fftw::plan(std::array<int, N>, double*,  std::complex<double>*, unsigned int)` |
| `fftw_plan_many_r2r` | `fftw::plan(std::array<int, N>, double*,  double*, unsigned int, fftw::r2r_kind*)` |
| `fftw_plan_many_dft` | `fftw::plan(std::array<int, N>, std::complex<double>*, int*, int, int, std::complex<double>*, int*, int, int, unsigned int, fftw::direction)` |
| `fftw_plan_many_dft_c2r` | `fftw::plan(std::array<int, N>, std::complex<double>*, int*, int, int,  double*, int*, int, int, unsigned int)` |
| `fftw_plan_many_dft_r2c` | `fftw::plan(std::array<int, N>, double*, int*, int, int,  std::complex<double>*, int*, int, int, unsigned int)` |
| `fftw_plan_many_r2r` | `fftw::plan(std::array<int, N>, double*, int*, int, int,  double*, int*, int, int, unsigned int, fftw::r2r_kind*)` |
| `fftw_plan_guru64_dft` | `fftw::plan(std::array<fftw::guru_params, N>, std::array<fftw::guru_params, N>, std::complex<double>*,  std::complex<double>*, unsigned int, fftw::direction)` |
| `fftw_plan_guru64_split_dft` | `fftw::plan(std::array<fftw::guru_params, N>, std::array<fftw::guru_params, N>, double*, double*, double*, double*, unsigned int)` |
| `fftw_plan_guru64_dft_c2r` | `fftw::plan(std::array<fftw::guru_params, N>, std::array<fftw::guru_params, N>, std::complex<double>*,  double*, unsigned int)` |
| `fftw_plan_guru64_split_dft_c2r` | `fftw::plan(fftw::split::c2r, std::array<fftw::guru_params, N>, std::array<fftw::guru_params, N>, double*, double*, double*, unsigned int)` |
| `fftw_plan_guru64_dft_r2c` | `fftw::plan(std::array<fftw::guru_params, N>, std::array<fftw::guru_params, N>, double*,  std::complex<double>*, unsigned int)` |
| `fftw_plan_guru64_split_dft_r2c` | `fftw::plan(fftw::split::r2c, std::array<fftw::guru_params, N>, std::array<fftw::guru_params, N>, double*, double*, double*, unsigned int)` |
| `fftw_plan_guru64_r2r` | `fftw::plan(std::array<fftw::guru_params, N>, std::array<fftw::guru_params, N>, double*,  double*, unsigned int, fftw::r2r_kind*)` |