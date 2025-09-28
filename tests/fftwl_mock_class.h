#pragma once
#include "gmock/gmock.h"
#include "fftw3.h"

namespace testing
{
	class mock_fftwl
	{
	public:
		~mock_fftwl() = default;

		MOCK_METHOD(void, fftwl_execute, (const fftwl_plan));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft, (int, const int*, fftwl_complex*, fftwl_complex*, int, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_1d, (int, fftwl_complex*, fftwl_complex*, int, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_2d, (int, int, fftwl_complex*, fftwl_complex*, int, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_3d, (int, int, int, fftwl_complex*, fftwl_complex*, int, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_many_dft, (int, const int*, int, fftwl_complex*, const int*, int, int, fftwl_complex*, const int*, int, int, int, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru_dft, (int, const fftwl_iodim*, int, const fftwl_iodim*, fftwl_complex*, fftwl_complex*, int, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru_split_dft, (int, const fftwl_iodim*, int, const fftwl_iodim*, long double*, long double*, long double*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru64_dft, (int, const fftwl_iodim64*, int, const fftwl_iodim64*, fftwl_complex*, fftwl_complex*, int, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru64_split_dft, (int, const fftwl_iodim64*, int, const fftwl_iodim64*, long double*, long double*, long double*, long double*, unsigned));
		MOCK_METHOD(void, fftwl_execute_dft, (const fftwl_plan, fftwl_complex*, fftwl_complex*));
		MOCK_METHOD(void, fftwl_execute_split_dft, (const fftwl_plan, long double*, long double*, long double*, long double*));
		MOCK_METHOD(fftwl_plan, fftwl_plan_many_dft_r2c, (int, const int*, int, long double*, const int*, int, int, fftwl_complex*, const int*, int, int, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_r2c, (int, const int*, long double*, fftwl_complex*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_r2c_1d, (int, long double*, fftwl_complex*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_r2c_2d, (int, int, long double*, fftwl_complex*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_r2c_3d, (int, int, int, long double*, fftwl_complex*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_many_dft_c2r, (int, const int*, int, fftwl_complex*, const int*, int, int, long double*, const int*, int, int, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_c2r, (int, const int*, fftwl_complex*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_c2r_1d, (int, fftwl_complex*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_c2r_2d, (int, int, fftwl_complex*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_dft_c2r_3d, (int, int, int, fftwl_complex*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru_dft_r2c, (int, const fftwl_iodim*, int, const fftwl_iodim*, long double*, fftwl_complex*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru_dft_c2r, (int, const fftwl_iodim*, int, const fftwl_iodim*, fftwl_complex*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru_split_dft_r2c, (int, const fftwl_iodim*, int, const fftwl_iodim*, long double*, long double*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru_split_dft_c2r, (int, const fftwl_iodim*, int, const fftwl_iodim*, long double*, long double*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru64_dft_r2c, (int, const fftwl_iodim64*, int, const fftwl_iodim64*, long double*, fftwl_complex*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru64_dft_c2r, (int, const fftwl_iodim64*, int, const fftwl_iodim64*, fftwl_complex*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru64_split_dft_r2c, (int, const fftwl_iodim64*, int, const fftwl_iodim64*, long double*, long double*, long double*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru64_split_dft_c2r, (int, const fftwl_iodim64*, int, const fftwl_iodim64*, long double*, long double*, long double*, unsigned));
		MOCK_METHOD(void, fftwl_execute_dft_r2c, (const fftwl_plan, long double*, fftwl_complex*));
		MOCK_METHOD(void, fftwl_execute_dft_c2r, (const fftwl_plan, fftwl_complex*, long double*));
		MOCK_METHOD(void, fftwl_execute_split_dft_r2c, (const fftwl_plan, long double*, long double*, long double*));
		MOCK_METHOD(void, fftwl_execute_split_dft_c2r, (const fftwl_plan, long double*, long double*, long double*));
		MOCK_METHOD(fftwl_plan, fftwl_plan_many_r2r, (int, const int*, int, long double*, const int*, int, int, long double*, const int*, int, int, const fftwl_r2r_kind*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_r2r, (int, const int*, long double*, long double*, const fftwl_r2r_kind*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_r2r_1d, (int, long double*, long double*, fftwl_r2r_kind, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_r2r_2d, (int, int, long double*, long double*, fftwl_r2r_kind, fftwl_r2r_kind, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_r2r_3d, (int, int, int, long double*, long double*, fftwl_r2r_kind, fftwl_r2r_kind, fftwl_r2r_kind, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru_r2r, (int, const fftwl_iodim*, int, const fftwl_iodim*, long double*, long double*, const fftwl_r2r_kind*, unsigned));
		MOCK_METHOD(fftwl_plan, fftwl_plan_guru64_r2r, (int, const fftwl_iodim64*, int, const fftwl_iodim64*, long double*, long double*, const fftwl_r2r_kind*, unsigned));
		MOCK_METHOD(void, fftwl_execute_r2r, (const fftwl_plan, long double*, long double*));
		MOCK_METHOD(fftwl_plan, fftwl_copy_plan, (fftwl_plan));
		MOCK_METHOD(void, fftwl_destroy_plan, (fftwl_plan));
		MOCK_METHOD(void, fftwl_forget_wisdom, ());
		MOCK_METHOD(void, fftwl_cleanup, ());
		MOCK_METHOD(void, fftwl_set_timelimit, (double));
		MOCK_METHOD(void, fftwl_plan_with_nthreads, (int));
		MOCK_METHOD(int, fftwl_planner_nthreads, ());
		MOCK_METHOD(int, fftwl_init_threads, ());
		MOCK_METHOD(void, fftwl_cleanup_threads, ());
		MOCK_METHOD(void, fftwl_threads_set_callback, (void (*parallel_loop)(void* (*work)(char*), char* jobdata, size_t elsize, int njobs, void* data), void* data));
		MOCK_METHOD(void, fftwl_make_planner_thread_safe, ());
		MOCK_METHOD(int, fftwl_export_wisdom_to_filename, (const char*));
		MOCK_METHOD(void, fftwl_export_wisdom_to_file, (FILE*));
		MOCK_METHOD(char*, fftwl_export_wisdom_to_string, ());
		MOCK_METHOD(void, fftwl_export_wisdom, (fftwl_write_char_func, void*));
		MOCK_METHOD(int, fftwl_import_system_wisdom, ());
		MOCK_METHOD(int, fftwl_import_wisdom_from_filename, (const char*));
		MOCK_METHOD(int, fftwl_import_wisdom_from_file, (FILE*));
		MOCK_METHOD(int, fftwl_import_wisdom_from_string, (const char*));
		MOCK_METHOD(int, fftwl_import_wisdom, (fftwl_read_char_func, void*));
		MOCK_METHOD(void, fftwl_fprint_plan, (const fftwl_plan, FILE*));
		MOCK_METHOD(void, fftwl_print_plan, (const fftwl_plan));
		MOCK_METHOD(char*, fftwl_sprint_plan, (const fftwl_plan));
		MOCK_METHOD(void*, fftwl_malloc, (size_t));
		MOCK_METHOD(long double*, fftwl_alloc_real, (size_t));
		MOCK_METHOD(fftwl_complex*, fftwl_alloc_complex, (size_t));
		MOCK_METHOD(void, fftwl_free, (void*));
		MOCK_METHOD(void, fftwl_flops, (const fftwl_plan, double*, double*, double*));
		MOCK_METHOD(double, fftwl_estimate_cost, (const fftwl_plan));
		MOCK_METHOD(double, fftwl_cost, (const fftwl_plan));
		MOCK_METHOD(int, fftwl_alignment_of, (long double*));


		static inline mock_fftwl* mock_ptr = nullptr;

		static void set_mock(mock_fftwl* p) { mock_ptr = p; }
		static mock_fftwl& mock_instance() { return *mock_ptr; }
	};

}