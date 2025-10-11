# FFTW Module #
A C++20 wrapper for FFTW3 that enables RAII and CTAD. Plan creation can be made by initializing `fftw::plan` with arguments similar to the plan creation functions in FFTW3.

This wrapper can either be added as a header-only library or a C++20 module. In both bases, the user needs to handle their own FFTW3 dependency.

Module support is tested with VS2022 on Windows and Ninja+Clang on Linux. I have not been able to get modules to work using g++-14 at this moment.

## Example ##
The following code is copied from the tutorial of FFTW3:
```cpp
#include <fftw3.h>
...
{
    fftw_complex *in, *out;
    fftw_plan p;
    ...
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    ...
    fftw_execute(p); /* repeat as needed */
    ...
    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);
}
```
With this wrapper, this can be rewritten as:
```cpp
import fftw_module;
...
{
    // fftw::vector uses custom allocators to call fftw_malloc, otherwise same as std::vector
    fftw::vector<std::complex<double>> in(N);   
    fftw::vector<std::complex<double>> out(N);
    ...
    // plan creation function is deduced from the input data type which is similar to the input used in the fftw3 API
    fftw::plan p(std::array<int, 1>{N}, in.data(), out.data(), fftw::optimization::estimate, fftw::director::forward);
    ...
    p.execute(); /* repeat as needed */
    ...
    // RAII handles plan destruction and memory deallocation
}
```
`fftw::plan` is a class template that knows the input and output types, which are used to call the correct plan construction and execution functions.

For more usage examples, please check [the](tests/fftw_tests.cpp) [test](tests/fftwf_tests.cpp) [code](tests/fftwl_tests.cpp)

# Supported FFTW3 features #
- Supported data types: float, double, long double
- `fftw::plan` is constructed by calling the following interfaces
    - basic interfaces (e.g. `fftw_plan_dft`)
    - advanced interfaces (e.g. `fftw_plan_many_dft`)
    - guru interfaces (e.g. `fftw_plan_guru_dft`, `fftw_plan_guru_split_dft`)
- `fftw::plan` can call `execute` to call the corresponding FFTW3 plan execution functions, the right function determined through the constructor of `fftw::plan`. 
    - this also include new array execute functions.
- Aligned memory allocation can be called with `fftw::vector`

# Notable differences to FFTW3 #
- There are no `fftw::plan` constructors for 1D, 2D, and 3D plans, only for nD plans. If there are cases where these functions would be useful, please let me know.
- In cases where the FFTW3 API asks for [array size, array data], the wrapper accepts a contiguous array instead. For example, the parameter of  `fftw_plan_dft` is `(int rank, const int *n, fftw_complex *in, ...)` where `rank` and `n` basically specify an interger array of size `rank` pointed by `n`. In this case, `rank` and `n` are replaced by contiguous containers of `int` such as `std::vector<int>` or `std::array<int, N>`. Any container that has `.size()` and `.data()` works.
- The position of the plan optimization flag argument is changed. In FFTW3 interfaces, the optimization flag is  specified last in plan creation functions, here, they are the second last argument when creating complex-to-complex or real-to-real functions. The reason being I want to make a single constructor for these plans and deduce the plan depending on whether direction, R2R transform type is given, and the only way I can think of is to stick this argument to the end as a parameter pack. Let me know if there are more elegant ways to implement this.
- `std::complex` is used for complex types, which has the same memory layout as the FFTW3 complex types such as `fftw_complex`
- Optimization flags and transform directions are now enums instead of macros

# Currently unsupportecd featuers #
The following features are not included in the wrapper:
- Quad precision data types
- Wisdom files: Right now I don't know how to deduce the type of plan from Wisdom files and the file format is not documented, so it would be up to the user to explicitly specify and remember than plan anyway. Not sure if I can make anything more useful with it in this wrapper
- Threading related utilities such as `fftw_init_threads`
- Other utilities provided by FFTW3 such as `fftw_alignment_of`, `fftw_flops`

# All feedback is welcome #
This is my first time playing around with C++20 features such as modules and concepts, also the first time I made a project with CMake and VCPKG. If there is anything I can improve on, please let me know!