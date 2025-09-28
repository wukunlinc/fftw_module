#include "fftw3.h"
#include "fftwl_mock_class.h"

void fftwl_execute(const fftwl_plan p)
{
	testing::mock_fftwl::mock_instance().fftwl_execute(p);
}
fftwl_plan fftwl_plan_dft(int rank, const int* n, fftwl_complex* in, fftwl_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft(rank, n, in, out, sign, flags);
}
fftwl_plan fftwl_plan_dft_1d(int n, fftwl_complex* in, fftwl_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_1d(n, in, out, sign, flags);
}
fftwl_plan fftwl_plan_dft_2d(int n0, int n1, fftwl_complex* in, fftwl_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_2d(n0, n1, in, out, sign, flags);
}
fftwl_plan fftwl_plan_dft_3d(int n0, int n1, int n2, fftwl_complex* in, fftwl_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_3d(n0, n1, n2, in, out, sign, flags);
}
fftwl_plan fftwl_plan_many_dft(int rank, const int* n, int howmany, fftwl_complex* in, const int* inembed, int istride, int idist, fftwl_complex* out, const int* onembed, int ostride, int odist, int sign, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_many_dft(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, sign, flags);
}
fftwl_plan fftwl_plan_guru_dft(int rank, const fftwl_iodim* dims, int howmany_rank, const fftwl_iodim* howmany_dims, fftwl_complex* in, fftwl_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru_dft(rank, dims, howmany_rank, howmany_dims, in, out, sign, flags);
}
fftwl_plan fftwl_plan_guru_split_dft(int rank, const fftwl_iodim* dims, int howmany_rank, const fftwl_iodim* howmany_dims, long double* ri, long double* ii, long double* ro, long double* io, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru_split_dft(rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags);
}
fftwl_plan fftwl_plan_guru64_dft(int rank, const fftwl_iodim64* dims, int howmany_rank, const fftwl_iodim64* howmany_dims, fftwl_complex* in, fftwl_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru64_dft(rank, dims, howmany_rank, howmany_dims, in, out, sign, flags);
}
fftwl_plan fftwl_plan_guru64_split_dft(int rank, const fftwl_iodim64* dims, int howmany_rank, const fftwl_iodim64* howmany_dims, long double* ri, long double* ii, long double* ro, long double* io, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru64_split_dft(rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags);
}
void fftwl_execute_dft(const fftwl_plan p, fftwl_complex* in, fftwl_complex* out)
{
	testing::mock_fftwl::mock_instance().fftwl_execute_dft(p, in, out);
}
void fftwl_execute_split_dft(const fftwl_plan p, long double* ri, long double* ii, long double* ro, long double* io)
{
	testing::mock_fftwl::mock_instance().fftwl_execute_split_dft(p, ri, ii, ro, io);
}
fftwl_plan fftwl_plan_many_dft_r2c(int rank, const int* n, int howmany, long double* in, const int* inembed, int istride, int idist, fftwl_complex* out, const int* onembed, int ostride, int odist, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_many_dft_r2c(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags);
}
fftwl_plan fftwl_plan_dft_r2c(int rank, const int* n, long double* in, fftwl_complex* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_r2c(rank, n, in, out, flags);
}
fftwl_plan fftwl_plan_dft_r2c_1d(int n, long double* in, fftwl_complex* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_r2c_1d(n, in, out, flags);
}
fftwl_plan fftwl_plan_dft_r2c_2d(int n0, int n1, long double* in, fftwl_complex* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_r2c_2d(n0, n1, in, out, flags);
}
fftwl_plan fftwl_plan_dft_r2c_3d(int n0, int n1, int n2, long double* in, fftwl_complex* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_r2c_3d(n0, n1, n2, in, out, flags);
}
fftwl_plan fftwl_plan_many_dft_c2r(int rank, const int* n, int howmany, fftwl_complex* in, const int* inembed, int istride, int idist, long double* out, const int* onembed, int ostride, int odist, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_many_dft_c2r(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags);
}
fftwl_plan fftwl_plan_dft_c2r(int rank, const int* n, fftwl_complex* in, long double* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_c2r(rank, n, in, out, flags);
}
fftwl_plan fftwl_plan_dft_c2r_1d(int n, fftwl_complex* in, long double* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_c2r_1d(n, in, out, flags);
}
fftwl_plan fftwl_plan_dft_c2r_2d(int n0, int n1, fftwl_complex* in, long double* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_c2r_2d(n0, n1, in, out, flags);
}
fftwl_plan fftwl_plan_dft_c2r_3d(int n0, int n1, int n2, fftwl_complex* in, long double* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_dft_c2r_3d(n0, n1, n2, in, out, flags);
}
fftwl_plan fftwl_plan_guru_dft_r2c(int rank, const fftwl_iodim* dims, int howmany_rank, const fftwl_iodim* howmany_dims, long double* in, fftwl_complex* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftwl_plan fftwl_plan_guru_dft_c2r(int rank, const fftwl_iodim* dims, int howmany_rank, const fftwl_iodim* howmany_dims, fftwl_complex* in, long double* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru_dft_c2r(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftwl_plan fftwl_plan_guru_split_dft_r2c(int rank, const fftwl_iodim* dims, int howmany_rank, const fftwl_iodim* howmany_dims, long double* in, long double* ro, long double* io, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru_split_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, ro, io, flags);
}
fftwl_plan fftwl_plan_guru_split_dft_c2r(int rank, const fftwl_iodim* dims, int howmany_rank, const fftwl_iodim* howmany_dims, long double* ri, long double* ii, long double* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru_split_dft_c2r(rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags);
}
fftwl_plan fftwl_plan_guru64_dft_r2c(int rank, const fftwl_iodim64* dims, int howmany_rank, const fftwl_iodim64* howmany_dims, long double* in, fftwl_complex* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru64_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftwl_plan fftwl_plan_guru64_dft_c2r(int rank, const fftwl_iodim64* dims, int howmany_rank, const fftwl_iodim64* howmany_dims, fftwl_complex* in, long double* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru64_dft_c2r(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftwl_plan fftwl_plan_guru64_split_dft_r2c(int rank, const fftwl_iodim64* dims, int howmany_rank, const fftwl_iodim64* howmany_dims, long double* in, long double* ro, long double* io, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru64_split_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, ro, io, flags);
}
fftwl_plan fftwl_plan_guru64_split_dft_c2r(int rank, const fftwl_iodim64* dims, int howmany_rank, const fftwl_iodim64* howmany_dims, long double* ri, long double* ii, long double* out, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru64_split_dft_c2r(rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags);
}
void fftwl_execute_dft_r2c(const fftwl_plan p, long double* in, fftwl_complex* out)
{
	testing::mock_fftwl::mock_instance().fftwl_execute_dft_r2c(p, in, out);
}
void fftwl_execute_dft_c2r(const fftwl_plan p, fftwl_complex* in, long double* out)
{
	testing::mock_fftwl::mock_instance().fftwl_execute_dft_c2r(p, in, out);
}
void fftwl_execute_split_dft_r2c(const fftwl_plan p, long double* in, long double* ro, long double* io)
{
	testing::mock_fftwl::mock_instance().fftwl_execute_split_dft_r2c(p, in, ro, io);
}
void fftwl_execute_split_dft_c2r(const fftwl_plan p, long double* ri, long double* ii, long double* out)
{
	testing::mock_fftwl::mock_instance().fftwl_execute_split_dft_c2r(p, ri, ii, out);
}
fftwl_plan fftwl_plan_many_r2r(int rank, const int* n, int howmany, long double* in, const int* inembed, int istride, int idist, long double* out, const int* onembed, int ostride, int odist, const fftwl_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_many_r2r(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, kind, flags);
}
fftwl_plan fftwl_plan_r2r(int rank, const int* n, long double* in, long double* out, const fftwl_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_r2r(rank, n, in, out, kind, flags);
}
fftwl_plan fftwl_plan_r2r_1d(int n, long double* in, long double* out, fftwl_r2r_kind kind, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_r2r_1d(n, in, out, kind, flags);
}
fftwl_plan fftwl_plan_r2r_2d(int n0, int n1, long double* in, long double* out, fftwl_r2r_kind kind0, fftwl_r2r_kind kind1, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_r2r_2d(n0, n1, in, out, kind0, kind1, flags);
}
fftwl_plan fftwl_plan_r2r_3d(int n0, int n1, int n2, long double* in, long double* out, fftwl_r2r_kind kind0, fftwl_r2r_kind kind1, fftwl_r2r_kind kind2, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_r2r_3d(n0, n1, n2, in, out, kind0, kind1, kind2, flags);
}
fftwl_plan fftwl_plan_guru_r2r(int rank, const fftwl_iodim* dims, int howmany_rank, const fftwl_iodim* howmany_dims, long double* in, long double* out, const fftwl_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru_r2r(rank, dims, howmany_rank, howmany_dims, in, out, kind, flags);
}
fftwl_plan fftwl_plan_guru64_r2r(int rank, const fftwl_iodim64* dims, int howmany_rank, const fftwl_iodim64* howmany_dims, long double* in, long double* out, const fftwl_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftwl::mock_instance().fftwl_plan_guru64_r2r(rank, dims, howmany_rank, howmany_dims, in, out, kind, flags);
}
void fftwl_execute_r2r(const fftwl_plan p, long double* in, long double* out)
{
	testing::mock_fftwl::mock_instance().fftwl_execute_r2r(p, in, out);
}
fftwl_plan fftwl_copy_plan(fftwl_plan p)
{
	return testing::mock_fftwl::mock_instance().fftwl_copy_plan(p);
}
void fftwl_destroy_plan(fftwl_plan p)
{
	testing::mock_fftwl::mock_instance().fftwl_destroy_plan(p);
}
void fftwl_forget_wisdom(void)
{
	testing::mock_fftwl::mock_instance().fftwl_forget_wisdom();
}
void fftwl_cleanup(void)
{
	testing::mock_fftwl::mock_instance().fftwl_cleanup();
}
void fftwl_set_timelimit(double t)
{
	testing::mock_fftwl::mock_instance().fftwl_set_timelimit(t);
}
void fftwl_plan_with_nthreads(int nthreads)
{
	testing::mock_fftwl::mock_instance().fftwl_plan_with_nthreads(nthreads);
}
int fftwl_planner_nthreads(void)
{
	return testing::mock_fftwl::mock_instance().fftwl_planner_nthreads();
}
int fftwl_init_threads(void)
{
	return testing::mock_fftwl::mock_instance().fftwl_init_threads();
}
void fftwl_cleanup_threads(void)
{
	testing::mock_fftwl::mock_instance().fftwl_cleanup_threads();
}
void fftwl_threads_set_callback(void (*parallel_loop)(void* (*work)(char*), char* jobdata, size_t elsize, int njobs, void* data), void* data)
{
	testing::mock_fftwl::mock_instance().fftwl_threads_set_callback(parallel_loop, data);
}
void fftwl_make_planner_thread_safe(void)
{
	testing::mock_fftwl::mock_instance().fftwl_make_planner_thread_safe();
}
int fftwl_export_wisdom_to_filename(const char* filename)
{
	return testing::mock_fftwl::mock_instance().fftwl_export_wisdom_to_filename(filename);
}
void fftwl_export_wisdom_to_file(FILE* output_file)
{
	testing::mock_fftwl::mock_instance().fftwl_export_wisdom_to_file(output_file);
}
char* fftwl_export_wisdom_to_string(void)
{
	return testing::mock_fftwl::mock_instance().fftwl_export_wisdom_to_string();
}
void fftwl_export_wisdom(fftwl_write_char_func write_char, void* data)
{
	testing::mock_fftwl::mock_instance().fftwl_export_wisdom(write_char, data);
}
int fftwl_import_system_wisdom(void)
{
	return testing::mock_fftwl::mock_instance().fftwl_import_system_wisdom();
}
int fftwl_import_wisdom_from_filename(const char* filename)
{
	return testing::mock_fftwl::mock_instance().fftwl_import_wisdom_from_filename(filename);
}
int fftwl_import_wisdom_from_file(FILE* input_file)
{
	return testing::mock_fftwl::mock_instance().fftwl_import_wisdom_from_file(input_file);
}
int fftwl_import_wisdom_from_string(const char* input_string)
{
	return testing::mock_fftwl::mock_instance().fftwl_import_wisdom_from_string(input_string);
}
int fftwl_import_wisdom(fftwl_read_char_func read_char, void* data)
{
	return testing::mock_fftwl::mock_instance().fftwl_import_wisdom(read_char, data);
}
void fftwl_fprint_plan(const fftwl_plan p, FILE* output_file)
{
	testing::mock_fftwl::mock_instance().fftwl_fprint_plan(p, output_file);
}
void fftwl_print_plan(const fftwl_plan p)
{
	testing::mock_fftwl::mock_instance().fftwl_print_plan(p);
}
char* fftwl_sprint_plan(const fftwl_plan p)
{
	return testing::mock_fftwl::mock_instance().fftwl_sprint_plan(p);
}
void* fftwl_malloc(size_t n)
{
	return testing::mock_fftwl::mock_instance().fftwl_malloc(n);
}
long double* fftwl_alloc_real(size_t n)
{
	return testing::mock_fftwl::mock_instance().fftwl_alloc_real(n);
}
fftwl_complex* fftwl_alloc_complex(size_t n)
{
	return testing::mock_fftwl::mock_instance().fftwl_alloc_complex(n);
}
void fftwl_free(void* p)
{
	testing::mock_fftwl::mock_instance().fftwl_free(p);
}
void fftwl_flops(const fftwl_plan p, double* add, double* mul, double* fmas)
{
	testing::mock_fftwl::mock_instance().fftwl_flops(p, add, mul, fmas);
}
double fftwl_estimate_cost(const fftwl_plan p)
{
	return testing::mock_fftwl::mock_instance().fftwl_estimate_cost(p);
}
double fftwl_cost(const fftwl_plan p)
{
	return testing::mock_fftwl::mock_instance().fftwl_cost(p);
}
int fftwl_alignment_of(long double* p)
{
	return testing::mock_fftwl::mock_instance().fftwl_alignment_of(p);
}
