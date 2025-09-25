#include "fftw3.h"
#include "fftw_mock_class.h"

void fftw_execute(const fftw_plan p)
{
	testing::mock_fftw::mock_instance().fftw_execute(p);
}
fftw_plan fftw_plan_dft(int rank, const int* n, fftw_complex* in, fftw_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft(rank, n, in, out, sign, flags);
}
fftw_plan fftw_plan_dft_1d(int n, fftw_complex* in, fftw_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_1d(n, in, out, sign, flags);
}
fftw_plan fftw_plan_dft_2d(int n0, int n1, fftw_complex* in, fftw_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_2d(n0, n1, in, out, sign, flags);
}
fftw_plan fftw_plan_dft_3d(int n0, int n1, int n2, fftw_complex* in, fftw_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_3d(n0, n1, n2, in, out, sign, flags);
}
fftw_plan fftw_plan_many_dft(int rank, const int* n, int howmany, fftw_complex* in, const int* inembed, int istride, int idist, fftw_complex* out, const int* onembed, int ostride, int odist, int sign, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_many_dft(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, sign, flags);
}
fftw_plan fftw_plan_guru_dft(int rank, const fftw_iodim* dims, int howmany_rank, const fftw_iodim* howmany_dims, fftw_complex* in, fftw_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru_dft(rank, dims, howmany_rank, howmany_dims, in, out, sign, flags);
}
fftw_plan fftw_plan_guru_split_dft(int rank, const fftw_iodim* dims, int howmany_rank, const fftw_iodim* howmany_dims, double* ri, double* ii, double* ro, double* io, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru_split_dft(rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags);
}
fftw_plan fftw_plan_guru64_dft(int rank, const fftw_iodim64* dims, int howmany_rank, const fftw_iodim64* howmany_dims, fftw_complex* in, fftw_complex* out, int sign, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru64_dft(rank, dims, howmany_rank, howmany_dims, in, out, sign, flags);
}
fftw_plan fftw_plan_guru64_split_dft(int rank, const fftw_iodim64* dims, int howmany_rank, const fftw_iodim64* howmany_dims, double* ri, double* ii, double* ro, double* io, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru64_split_dft(rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags);
}
void fftw_execute_dft(const fftw_plan p, fftw_complex* in, fftw_complex* out)
{
	testing::mock_fftw::mock_instance().fftw_execute_dft(p, in, out);
}
void fftw_execute_split_dft(const fftw_plan p, double* ri, double* ii, double* ro, double* io)
{
	testing::mock_fftw::mock_instance().fftw_execute_split_dft(p, ri, ii, ro, io);
}
fftw_plan fftw_plan_many_dft_r2c(int rank, const int* n, int howmany, double* in, const int* inembed, int istride, int idist, fftw_complex* out, const int* onembed, int ostride, int odist, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_many_dft_r2c(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags);
}
fftw_plan fftw_plan_dft_r2c(int rank, const int* n, double* in, fftw_complex* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_r2c(rank, n, in, out, flags);
}
fftw_plan fftw_plan_dft_r2c_1d(int n, double* in, fftw_complex* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_r2c_1d(n, in, out, flags);
}
fftw_plan fftw_plan_dft_r2c_2d(int n0, int n1, double* in, fftw_complex* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_r2c_2d(n0, n1, in, out, flags);
}
fftw_plan fftw_plan_dft_r2c_3d(int n0, int n1, int n2, double* in, fftw_complex* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_r2c_3d(n0, n1, n2, in, out, flags);
}
fftw_plan fftw_plan_many_dft_c2r(int rank, const int* n, int howmany, fftw_complex* in, const int* inembed, int istride, int idist, double* out, const int* onembed, int ostride, int odist, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_many_dft_c2r(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags);
}
fftw_plan fftw_plan_dft_c2r(int rank, const int* n, fftw_complex* in, double* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_c2r(rank, n, in, out, flags);
}
fftw_plan fftw_plan_dft_c2r_1d(int n, fftw_complex* in, double* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_c2r_1d(n, in, out, flags);
}
fftw_plan fftw_plan_dft_c2r_2d(int n0, int n1, fftw_complex* in, double* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_c2r_2d(n0, n1, in, out, flags);
}
fftw_plan fftw_plan_dft_c2r_3d(int n0, int n1, int n2, fftw_complex* in, double* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_dft_c2r_3d(n0, n1, n2, in, out, flags);
}
fftw_plan fftw_plan_guru_dft_r2c(int rank, const fftw_iodim* dims, int howmany_rank, const fftw_iodim* howmany_dims, double* in, fftw_complex* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftw_plan fftw_plan_guru_dft_c2r(int rank, const fftw_iodim* dims, int howmany_rank, const fftw_iodim* howmany_dims, fftw_complex* in, double* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru_dft_c2r(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftw_plan fftw_plan_guru_split_dft_r2c(int rank, const fftw_iodim* dims, int howmany_rank, const fftw_iodim* howmany_dims, double* in, double* ro, double* io, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru_split_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, ro, io, flags);
}
fftw_plan fftw_plan_guru_split_dft_c2r(int rank, const fftw_iodim* dims, int howmany_rank, const fftw_iodim* howmany_dims, double* ri, double* ii, double* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru_split_dft_c2r(rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags);
}
fftw_plan fftw_plan_guru64_dft_r2c(int rank, const fftw_iodim64* dims, int howmany_rank, const fftw_iodim64* howmany_dims, double* in, fftw_complex* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru64_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftw_plan fftw_plan_guru64_dft_c2r(int rank, const fftw_iodim64* dims, int howmany_rank, const fftw_iodim64* howmany_dims, fftw_complex* in, double* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru64_dft_c2r(rank, dims, howmany_rank, howmany_dims, in, out, flags);
}
fftw_plan fftw_plan_guru64_split_dft_r2c(int rank, const fftw_iodim64* dims, int howmany_rank, const fftw_iodim64* howmany_dims, double* in, double* ro, double* io, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru64_split_dft_r2c(rank, dims, howmany_rank, howmany_dims, in, ro, io, flags);
}
fftw_plan fftw_plan_guru64_split_dft_c2r(int rank, const fftw_iodim64* dims, int howmany_rank, const fftw_iodim64* howmany_dims, double* ri, double* ii, double* out, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru64_split_dft_c2r(rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags);
}
void fftw_execute_dft_r2c(const fftw_plan p, double* in, fftw_complex* out)
{
	testing::mock_fftw::mock_instance().fftw_execute_dft_r2c(p, in, out);
}
void fftw_execute_dft_c2r(const fftw_plan p, fftw_complex* in, double* out)
{
	testing::mock_fftw::mock_instance().fftw_execute_dft_c2r(p, in, out);
}
void fftw_execute_split_dft_r2c(const fftw_plan p, double* in, double* ro, double* io)
{
	testing::mock_fftw::mock_instance().fftw_execute_split_dft_r2c(p, in, ro, io);
}
void fftw_execute_split_dft_c2r(const fftw_plan p, double* ri, double* ii, double* out)
{
	testing::mock_fftw::mock_instance().fftw_execute_split_dft_c2r(p, ri, ii, out);
}
fftw_plan fftw_plan_many_r2r(int rank, const int* n, int howmany, double* in, const int* inembed, int istride, int idist, double* out, const int* onembed, int ostride, int odist, const fftw_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_many_r2r(rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, kind, flags);
}
fftw_plan fftw_plan_r2r(int rank, const int* n, double* in, double* out, const fftw_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_r2r(rank, n, in, out, kind, flags);
}
fftw_plan fftw_plan_r2r_1d(int n, double* in, double* out, fftw_r2r_kind kind, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_r2r_1d(n, in, out, kind, flags);
}
fftw_plan fftw_plan_r2r_2d(int n0, int n1, double* in, double* out, fftw_r2r_kind kind0, fftw_r2r_kind kind1, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_r2r_2d(n0, n1, in, out, kind0, kind1, flags);
}
fftw_plan fftw_plan_r2r_3d(int n0, int n1, int n2, double* in, double* out, fftw_r2r_kind kind0, fftw_r2r_kind kind1, fftw_r2r_kind kind2, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_r2r_3d(n0, n1, n2, in, out, kind0, kind1, kind2, flags);
}
fftw_plan fftw_plan_guru_r2r(int rank, const fftw_iodim* dims, int howmany_rank, const fftw_iodim* howmany_dims, double* in, double* out, const fftw_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru_r2r(rank, dims, howmany_rank, howmany_dims, in, out, kind, flags);
}
fftw_plan fftw_plan_guru64_r2r(int rank, const fftw_iodim64* dims, int howmany_rank, const fftw_iodim64* howmany_dims, double* in, double* out, const fftw_r2r_kind* kind, unsigned flags)
{
	return testing::mock_fftw::mock_instance().fftw_plan_guru64_r2r(rank, dims, howmany_rank, howmany_dims, in, out, kind, flags);
}
void fftw_execute_r2r(const fftw_plan p, double* in, double* out)
{
	testing::mock_fftw::mock_instance().fftw_execute_r2r(p, in, out);
}
fftw_plan fftw_copy_plan(fftw_plan p)
{
	return testing::mock_fftw::mock_instance().fftw_copy_plan(p);
}
void fftw_destroy_plan(fftw_plan p)
{
	testing::mock_fftw::mock_instance().fftw_destroy_plan(p);
}
void fftw_forget_wisdom(void)
{
	testing::mock_fftw::mock_instance().fftw_forget_wisdom();
}
void fftw_cleanup(void)
{
	testing::mock_fftw::mock_instance().fftw_cleanup();
}
void fftw_set_timelimit(double t)
{
	testing::mock_fftw::mock_instance().fftw_set_timelimit(t);
}
void fftw_plan_with_nthreads(int nthreads)
{
	testing::mock_fftw::mock_instance().fftw_plan_with_nthreads(nthreads);
}
int fftw_planner_nthreads(void)
{
	return testing::mock_fftw::mock_instance().fftw_planner_nthreads();
}
int fftw_init_threads(void)
{
	return testing::mock_fftw::mock_instance().fftw_init_threads();
}
void fftw_cleanup_threads(void)
{
	testing::mock_fftw::mock_instance().fftw_cleanup_threads();
}
void fftw_threads_set_callback(void (*parallel_loop)(void* (*work)(char*), char* jobdata, size_t elsize, int njobs, void* data), void* data)
{
	testing::mock_fftw::mock_instance().fftw_threads_set_callback();
}
void fftw_make_planner_thread_safe(void)
{
	testing::mock_fftw::mock_instance().fftw_make_planner_thread_safe();
}
int fftw_export_wisdom_to_filename(const char* filename)
{
	return testing::mock_fftw::mock_instance().fftw_export_wisdom_to_filename(filename);
}
void fftw_export_wisdom_to_file(FILE* output_file)
{
	testing::mock_fftw::mock_instance().fftw_export_wisdom_to_file(output_file);
}
char*  fftw_export_wisdom_to_string(void)
{
	return testing::mock_fftw::mock_instance().fftw_export_wisdom_to_string();
}
void fftw_export_wisdom(fftw_write_char_func write_char, void* data)
{
	testing::mock_fftw::mock_instance().fftw_export_wisdom(write_char, data);
}
int fftw_import_system_wisdom(void)
{
	return testing::mock_fftw::mock_instance().fftw_import_system_wisdom();
}
int fftw_import_wisdom_from_filename(const char* filename)
{
	return testing::mock_fftw::mock_instance().fftw_import_wisdom_from_filename(filename);
}
int fftw_import_wisdom_from_file(FILE* input_file)
{
	return testing::mock_fftw::mock_instance().fftw_import_wisdom_from_file(input_file);
}
int fftw_import_wisdom_from_string(const char* input_string)
{
	return testing::mock_fftw::mock_instance().fftw_import_wisdom_from_string(input_string);
}
int fftw_import_wisdom(fftw_read_char_func read_char, void* data)
{
	return testing::mock_fftw::mock_instance().fftw_import_wisdom(read_char, data);
}
void fftw_fprint_plan(const fftw_plan p, FILE* output_file)
{
	testing::mock_fftw::mock_instance().fftw_fprint_plan(p, output_file);
}
void fftw_print_plan(const fftw_plan p)
{
	testing::mock_fftw::mock_instance().fftw_print_plan(p);
}
char*  fftw_sprint_plan(const fftw_plan p)
{
	return testing::mock_fftw::mock_instance().fftw_sprint_plan(p);
}
void*  fftw_malloc(size_t n)
{
	return testing::mock_fftw::mock_instance().fftw_malloc(n);
}
double*  fftw_alloc_real(size_t n)
{
	return testing::mock_fftw::mock_instance().fftw_alloc_real(n);
}
fftw_complex*  fftw_alloc_complex(size_t n)
{
	return testing::mock_fftw::mock_instance().fftw_alloc_complex(n);
}
void fftw_free(void* p)
{
	testing::mock_fftw::mock_instance().fftw_free(p);
}
void fftw_flops(const fftw_plan p, double* add, double* mul, double* fmas)
{
	testing::mock_fftw::mock_instance().fftw_flops(p, add, mul, fmas);
}
double fftw_estimate_cost(const fftw_plan p)
{
	return testing::mock_fftw::mock_instance().fftw_estimate_cost(p);
}
double fftw_cost(const fftw_plan p)
{
	return testing::mock_fftw::mock_instance().fftw_cost(p);
}
int fftw_alignment_of(double* p)
{
	return testing::mock_fftw::mock_instance().fftw_alignment_of(p);
}