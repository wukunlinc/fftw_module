export module fftw_module;

import "fftw3.h";
import std;

namespace fftw
{

	export fftw_plan fftw_plan_dft(int rank, const int* n, fftw_complex* in, fftw_complex* out, int sign, unsigned flags)
	{
		return ::fftw_plan_dft(rank, n, in, out, sign, flags);
	}
}
