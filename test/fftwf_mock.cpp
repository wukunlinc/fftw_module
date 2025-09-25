#include "fftw3.h"
#include "fftwf_mock_class.h"

void FFTW_CDECL fftwf_execute(const fftwf_plan p)
{
	testing::mock_fftwf::mock_instance().fftwf_execute(p);
}
fftwf_plan fftwf_plan_dft(int rank, const int* n, fftwf_complex* in, fftwf_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft(rank, n, in, out, sign, flags);
}
fftwf_plan fftwf_plan_dft_1d(int n, fftwf_complex* in, fftwf_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_1d(n, in, out, sign, flags);
}
fftwf_plan fftwf_plan_dft_2d(int n0, int n1, fftwf_complex* in, fftwf_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_2d(n0, n1, in, out, sign, flags);
}
fftwf_plan fftwf_plan_dft_3d(int n0, int n1, int n2, fftwf_complex* in, fftwf_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_3d(n0, n1, n2, in, out, sign, flags);
}
fftwf_plan fftwf_plan_many_dft(int rank, const int* n, int howmany, fftwf_complex* in, const int* inembed, int istride, int idist, fftwf_complex* out, const int* onembed, int ostride, int odist, int sign, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_many_dft(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, sign, flags);
}
fftwf_plan fftwf_plan_guru_dft(int rank, const fftwf_iodim* dims, int howmany_rank, const fftwf_iodim* howmany_dims, fftwf_complex* in, fftwf_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru_dft(rank, dims, howmany_rank, howmany_dims, in, out, sign, flags);
}
fftwf_plan fftwf_plan_guru_split_dft(int rank, const fftwf_iodim* dims, int howmany_rank, const fftwf_iodim* howmany_dims, float* ri, float* ii, float* ro, float* io, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru_split_dft(rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags);
}
fftwf_plan fftwf_plan_guru64_dft(int rank, const fftwf_iodim64* dims, int howmany_rank, const fftwf_iodim64* howmany_dims, fftwf_complex* in, fftwf_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru64_dft(rank, dims, howmany_rank, howmany_dims, in, out, sign, flags);
}
fftwf_plan fftwf_plan_guru64_split_dft(int rank, const fftwf_iodim64* dims, int howmany_rank, const fftwf_iodim64* howmany_dims, float* ri, float* ii, float* ro, float* io, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru64_split_dft(rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags);
}
void FFTW_CDECL fftwf_execute_dft(const fftwf_plan p, fftwf_complex* in, fftwf_complex* out)
{
	testing::mock_fftwf::mock_instance().fftwf_execute_dft(p, in, out);
}
void FFTW_CDECL fftwf_execute_split_dft(const fftwf_plan p, float* ri, float* ii, float* ro, float* io)
{
	testing::mock_fftwf::mock_instance().fftwf_execute_split_dft(p, ri, ii, ro, io);
}
fftwf_plan fftwf_plan_many_dft_r2c(int rank, const int* n, int howmany, float* in, const int* inembed, int istride, int idist, fftwf_complex* out, const int* onembed, int ostride, int odist, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_many_dft_r2c(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags);
}
fftwf_plan fftwf_plan_dft_r2c(int rank, const int* n, float* in, fftwf_complex* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_r2c(rank, n, in, out, flags);
}
fftwf_plan fftwf_plan_dft_r2c_1d(int n, float* in, fftwf_complex* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_r2c_1d(n, in, out, flags);
}
fftwf_plan fftwf_plan_dft_r2c_2d(int n0, int n1, float* in, fftwf_complex* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_r2c_2d(n0, n1, in, out, flags);
}
fftwf_plan fftwf_plan_dft_r2c_3d(int n0, int n1, int n2, float* in, fftwf_complex* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_r2c_3d(n0, n1, n2, in, out, flags);
}
fftwf_plan fftwf_plan_many_dft_c2r(int rank, const int* n, int howmany, fftwf_complex* in, const int* inembed, int istride, int idist, float* out, const int* onembed, int ostride, int odist, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_many_dft_c2r(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags);
}
fftwf_plan fftwf_plan_dft_c2r(int rank, const int* n, fftwf_complex* in, float* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_c2r(rank, n, in, out, flags);
}
fftwf_plan fftwf_plan_dft_c2r_1d(int n, fftwf_complex* in, float* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_c2r_1d(n, in, out, flags);
}
fftwf_plan fftwf_plan_dft_c2r_2d(int n0, int n1, fftwf_complex* in, float* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_c2r_2d(n0, n1, in, out, flags);
}
fftwf_plan fftwf_plan_dft_c2r_3d(int n0, int n1, int n2, fftwf_complex* in, float* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_dft_c2r_3d(n0, n1, n2, in, out, flags);
}
fftwf_plan fftwf_plan_guru_dft_r2c(int rank, const fftwf_iodim* dims, int howmany_rank, const fftwf_iodim* howmany_dims, float* in, fftwf_complex* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftwf_plan fftwf_plan_guru_dft_c2r(int rank, const fftwf_iodim* dims, int howmany_rank, const fftwf_iodim* howmany_dims, fftwf_complex* in, float* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru_dft_c2r(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftwf_plan fftwf_plan_guru_split_dft_r2c(int rank, const fftwf_iodim* dims, int howmany_rank, const fftwf_iodim* howmany_dims, float* in, float* ro, float* io, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru_split_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, ro, io, flags);
}
fftwf_plan fftwf_plan_guru_split_dft_c2r(int rank, const fftwf_iodim* dims, int howmany_rank, const fftwf_iodim* howmany_dims, float* ri, float* ii, float* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru_split_dft_c2r(rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags);
}
fftwf_plan fftwf_plan_guru64_dft_r2c(int rank, const fftwf_iodim64* dims, int howmany_rank, const fftwf_iodim64* howmany_dims, float* in, fftwf_complex* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru64_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftwf_plan fftwf_plan_guru64_dft_c2r(int rank, const fftwf_iodim64* dims, int howmany_rank, const fftwf_iodim64* howmany_dims, fftwf_complex* in, float* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru64_dft_c2r(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftwf_plan fftwf_plan_guru64_split_dft_r2c(int rank, const fftwf_iodim64* dims, int howmany_rank, const fftwf_iodim64* howmany_dims, float* in, float* ro, float* io, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru64_split_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, ro, io, flags);
}
fftwf_plan fftwf_plan_guru64_split_dft_c2r(int rank, const fftwf_iodim64* dims, int howmany_rank, const fftwf_iodim64* howmany_dims, float* ri, float* ii, float* out, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru64_split_dft_c2r(rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags);
}
void FFTW_CDECL fftwf_execute_dft_r2c(const fftwf_plan p, float* in, fftwf_complex* out)
{
	testing::mock_fftwf::mock_instance().fftwf_execute_dft_r2c(p, in, out);
}
void FFTW_CDECL fftwf_execute_dft_c2r(const fftwf_plan p, fftwf_complex* in, float* out)
{
	testing::mock_fftwf::mock_instance().fftwf_execute_dft_c2r(p, in, out);
}
void FFTW_CDECL fftwf_execute_split_dft_r2c(const fftwf_plan p, float* in, float* ro, float* io)
{
	testing::mock_fftwf::mock_instance().fftwf_execute_split_dft_r2c(p, in, ro, io);
}
void FFTW_CDECL fftwf_execute_split_dft_c2r(const fftwf_plan p, float* ri, float* ii, float* out)
{
	testing::mock_fftwf::mock_instance().fftwf_execute_split_dft_c2r(p, ri, ii, out);
}
fftwf_plan fftwf_plan_many_r2r(int rank, const int* n, int howmany, float* in, const int* inembed, int istride, int idist, float* out, const int* onembed, int ostride, int odist, const fftwf_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_many_r2r(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, kind, flags);
}
fftwf_plan fftwf_plan_r2r(int rank, const int* n, float* in, float* out, const fftwf_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_r2r(rank, n, in, out, kind, flags);
}
fftwf_plan fftwf_plan_r2r_1d(int n, float* in, float* out, fftwf_r2r_kind kind, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_r2r_1d(n, in, out, kind, flags);
}
fftwf_plan fftwf_plan_r2r_2d(int n0, int n1, float* in, float* out, fftwf_r2r_kind kind0, fftwf_r2r_kind kind1, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_r2r_2d(n0, n1, in, out, kind0, kind1, flags);
}
fftwf_plan fftwf_plan_r2r_3d(int n0, int n1, int n2, float* in, float* out, fftwf_r2r_kind kind0, fftwf_r2r_kind kind1, fftwf_r2r_kind kind2, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_r2r_3d(n0, n1, n2, in, out, kind0, kind1, kind2, flags);
}
fftwf_plan fftwf_plan_guru_r2r(int rank, const fftwf_iodim* dims, int howmany_rank, const fftwf_iodim* howmany_dims, float* in, float* out, const fftwf_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru_r2r(rank, dims, howmany_rank, howmany_dims, in, out, kind, flags);
}
fftwf_plan fftwf_plan_guru64_r2r(int rank, const fftwf_iodim64* dims, int howmany_rank, const fftwf_iodim64* howmany_dims, float* in, float* out, const fftwf_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftwf::mock_instance().fftwf_plan_guru64_r2r(rank, dims, howmany_rank, howmany_dims, in, out, kind, flags);
}
void FFTW_CDECL fftwf_execute_r2r(const fftwf_plan p, float* in, float* out)
{
	testing::mock_fftwf::mock_instance().fftwf_execute_r2r(p, in, out);
}
fftwf_plan FFTW_CDECL fftwf_copy_plan(fftwf_plan p)
{
	return testing::mock_fftwf::mock_instance().fftwf_copy_plan(p);
}
void FFTW_CDECL fftwf_destroy_plan(fftwf_plan p)
{
	testing::mock_fftwf::mock_instance().fftwf_destroy_plan(p);
}
void FFTW_CDECL fftwf_forget_wisdom(void)
{
	testing::mock_fftwf::mock_instance().fftwf_forget_wisdom();
}
void FFTW_CDECL fftwf_cleanup(void)
{
	testing::mock_fftwf::mock_instance().fftwf_cleanup();
}
void FFTW_CDECL fftwf_set_timelimit(double t)
{
	testing::mock_fftwf::mock_instance().fftwf_set_timelimit(t);
}
void fftwf_plan_with_nthreads(int nthreads)
{
	testing::mock_fftwf::mock_instance().fftwf_plan_with_nthreads(nthreads);
}
int fftwf_planner_nthreads(void)
{
	return testing::mock_fftwf::mock_instance().fftwf_planner_nthreads();
}
int FFTW_CDECL fftwf_init_threads(void)
{
	return testing::mock_fftwf::mock_instance().fftwf_init_threads();
}
void FFTW_CDECL fftwf_cleanup_threads(void)
{
	testing::mock_fftwf::mock_instance().fftwf_cleanup_threads();
}
void FFTW_CDECL fftwf_threads_set_callback(void (*parallel_loop)(void* (*work)(char*), char* jobdata, size_t elsize, int njobs, void* data), void* data)
{
	testing::mock_fftwf::mock_instance().fftwf_threads_set_callback();
}
void FFTW_CDECL fftwf_make_planner_thread_safe(void)
{
	testing::mock_fftwf::mock_instance().fftwf_make_planner_thread_safe();
}
int FFTW_CDECL fftwf_export_wisdom_to_filename(const char* filename)
{
	return testing::mock_fftwf::mock_instance().fftwf_export_wisdom_to_filename(filename);
}
void FFTW_CDECL fftwf_export_wisdom_to_file(FILE* output_file)
{
	testing::mock_fftwf::mock_instance().fftwf_export_wisdom_to_file(output_file);
}
char* FFTW_CDECL fftwf_export_wisdom_to_string(void)
{
	return testing::mock_fftwf::mock_instance().fftwf_export_wisdom_to_string();
}
void FFTW_CDECL fftwf_export_wisdom(fftwf_write_char_func write_char, void* data)
{
	testing::mock_fftwf::mock_instance().fftwf_export_wisdom(write_char, data);
}
int FFTW_CDECL fftwf_import_system_wisdom(void)
{
	return testing::mock_fftwf::mock_instance().fftwf_import_system_wisdom();
}
int FFTW_CDECL fftwf_import_wisdom_from_filename(const char* filename)
{
	return testing::mock_fftwf::mock_instance().fftwf_import_wisdom_from_filename(filename);
}
int FFTW_CDECL fftwf_import_wisdom_from_file(FILE* input_file)
{
	return testing::mock_fftwf::mock_instance().fftwf_import_wisdom_from_file(input_file);
}
int FFTW_CDECL fftwf_import_wisdom_from_string(const char* input_string)
{
	return testing::mock_fftwf::mock_instance().fftwf_import_wisdom_from_string(input_string);
}
int FFTW_CDECL fftwf_import_wisdom(fftwf_read_char_func read_char, void* data)
{
	return testing::mock_fftwf::mock_instance().fftwf_import_wisdom(read_char, data);
}
void FFTW_CDECL fftwf_fprint_plan(const fftwf_plan p, FILE* output_file)
{
	testing::mock_fftwf::mock_instance().fftwf_fprint_plan(p, output_file);
}
void FFTW_CDECL fftwf_print_plan(const fftwf_plan p)
{
	testing::mock_fftwf::mock_instance().fftwf_print_plan(p);
}
char* FFTW_CDECL fftwf_sprint_plan(const fftwf_plan p)
{
	return testing::mock_fftwf::mock_instance().fftwf_sprint_plan(p);
}
void* FFTW_CDECL fftwf_malloc(size_t n)
{
	return testing::mock_fftwf::mock_instance().fftwf_malloc(n);
}
float* FFTW_CDECL fftwf_alloc_real(size_t n)
{
	return testing::mock_fftwf::mock_instance().fftwf_alloc_real(n);
}
fftwf_complex* FFTW_CDECL fftwf_alloc_complex(size_t n)
{
	return testing::mock_fftwf::mock_instance().fftwf_alloc_complex(n);
}
void FFTW_CDECL fftwf_free(void* p)
{
	testing::mock_fftwf::mock_instance().fftwf_free(p);
}
void FFTW_CDECL fftwf_flops(const fftwf_plan p, double* add, double* mul, double* fmas)
{
	testing::mock_fftwf::mock_instance().fftwf_flops(p, add, mul, fmas);
}
double FFTW_CDECL fftwf_estimate_cost(const fftwf_plan p)
{
	return testing::mock_fftwf::mock_instance().fftwf_estimate_cost(p);
}
double FFTW_CDECL fftwf_cost(const fftwf_plan p)
{
	return testing::mock_fftwf::mock_instance().fftwf_cost(p);
}
int FFTW_CDECL fftwf_alignment_of(float* p)
{
	return testing::mock_fftwf::mock_instance().fftwf_alignment_of(p);
}