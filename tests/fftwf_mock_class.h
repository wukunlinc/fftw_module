#pragma once
#include "gmock/gmock.h"
#include "fftw3.h"

namespace testing
{
	class mock_fftwf
	{
	public:
		~mock_fftwf() = default;

		MOCK_METHOD(void, fftwf_execute, (const  fftwf_plan));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft, (int, const  int*, fftwf_complex*, fftwf_complex*, int, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_1d, (int, fftwf_complex*, fftwf_complex*, int, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_2d, (int, int, fftwf_complex*, fftwf_complex*, int, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_3d, (int, int, int, fftwf_complex*, fftwf_complex*, int, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_many_dft, (int, const  int*, int, fftwf_complex*, const  int*, int, int, fftwf_complex*, const  int*, int, int, int, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru_dft, (int, const  fftwf_iodim*, int, const  fftwf_iodim*, fftwf_complex*, fftwf_complex*, int, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru_split_dft, (int, const  fftwf_iodim*, int, const  fftwf_iodim*, float*, float*, float*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru64_dft, (int, const  fftwf_iodim64*, int, const  fftwf_iodim64*, fftwf_complex*, fftwf_complex*, int, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru64_split_dft, (int, const  fftwf_iodim64*, int, const  fftwf_iodim64*, float*, float*, float*, float*, unsigned));
		MOCK_METHOD(void, fftwf_execute_dft, (const  fftwf_plan, fftwf_complex*, fftwf_complex*));
		MOCK_METHOD(void, fftwf_execute_split_dft, (const  fftwf_plan, float*, float*, float*, float*));
		MOCK_METHOD(fftwf_plan, fftwf_plan_many_dft_r2c, (int, const  int*, int, float*, const  int*, int, int, fftwf_complex*, const  int*, int, int, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_r2c, (int, const  int*, float*, fftwf_complex*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_r2c_1d, (int, float*, fftwf_complex*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_r2c_2d, (int, int, float*, fftwf_complex*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_r2c_3d, (int, int, int, float*, fftwf_complex*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_many_dft_c2r, (int, const  int*, int, fftwf_complex*, const  int*, int, int, float*, const  int*, int, int, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_c2r, (int, const  int*, fftwf_complex*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_c2r_1d, (int, fftwf_complex*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_c2r_2d, (int, int, fftwf_complex*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_dft_c2r_3d, (int, int, int, fftwf_complex*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru_dft_r2c, (int, const  fftwf_iodim*, int, const  fftwf_iodim*, float*, fftwf_complex*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru_dft_c2r, (int, const  fftwf_iodim*, int, const  fftwf_iodim*, fftwf_complex*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru_split_dft_r2c, (int, const  fftwf_iodim*, int, const  fftwf_iodim*, float*, float*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru_split_dft_c2r, (int, const  fftwf_iodim*, int, const  fftwf_iodim*, float*, float*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru64_dft_r2c, (int, const  fftwf_iodim64*, int, const  fftwf_iodim64*, float*, fftwf_complex*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru64_dft_c2r, (int, const  fftwf_iodim64*, int, const  fftwf_iodim64*, fftwf_complex*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru64_split_dft_r2c, (int, const  fftwf_iodim64*, int, const  fftwf_iodim64*, float*, float*, float*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru64_split_dft_c2r, (int, const  fftwf_iodim64*, int, const  fftwf_iodim64*, float*, float*, float*, unsigned));
		MOCK_METHOD(void, fftwf_execute_dft_r2c, (const  fftwf_plan, float*, fftwf_complex*));
		MOCK_METHOD(void, fftwf_execute_dft_c2r, (const  fftwf_plan, fftwf_complex*, float*));
		MOCK_METHOD(void, fftwf_execute_split_dft_r2c, (const  fftwf_plan, float*, float*, float*));
		MOCK_METHOD(void, fftwf_execute_split_dft_c2r, (const  fftwf_plan, float*, float*, float*));
		MOCK_METHOD(fftwf_plan, fftwf_plan_many_r2r, (int, const  int*, int, float*, const  int*, int, int, float*, const  int*, int, int, const  fftwf_r2r_kind*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_r2r, (int, const  int*, float*, float*, const  fftwf_r2r_kind*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_r2r_1d, (int, float*, float*, fftwf_r2r_kind, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_r2r_2d, (int, int, float*, float*, fftwf_r2r_kind, fftwf_r2r_kind, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_r2r_3d, (int, int, int, float*, float*, fftwf_r2r_kind, fftwf_r2r_kind, fftwf_r2r_kind, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru_r2r, (int, const  fftwf_iodim*, int, const  fftwf_iodim*, float*, float*, const  fftwf_r2r_kind*, unsigned));
		MOCK_METHOD(fftwf_plan, fftwf_plan_guru64_r2r, (int, const  fftwf_iodim64*, int, const  fftwf_iodim64*, float*, float*, const  fftwf_r2r_kind*, unsigned));
		MOCK_METHOD(void, fftwf_execute_r2r, (const  fftwf_plan, float*, float*));
		MOCK_METHOD(fftwf_plan, fftwf_copy_plan, (fftwf_plan));
		MOCK_METHOD(void, fftwf_destroy_plan, (fftwf_plan));
		MOCK_METHOD(void, fftwf_forget_wisdom, ());
		MOCK_METHOD(void, fftwf_cleanup, ());
		MOCK_METHOD(void, fftwf_set_timelimit, (double));
		MOCK_METHOD(void, fftwf_plan_with_nthreads, (int));
		MOCK_METHOD(int, fftwf_planner_nthreads, ());
		MOCK_METHOD(int, fftwf_init_threads, ());
		MOCK_METHOD(void, fftwf_cleanup_threads, ());
		MOCK_METHOD(void, fftwf_threads_set_callback, (void (*parallel_loop)(void* (*work)(char*), char* jobdata, size_t elsize, int njobs, void* data), void* data));
		MOCK_METHOD(void, fftwf_make_planner_thread_safe, ());
		MOCK_METHOD(int, fftwf_export_wisdom_to_filename, (const  char*));
		MOCK_METHOD(void, fftwf_export_wisdom_to_file, (FILE*));
		MOCK_METHOD(char*, fftwf_export_wisdom_to_string, ());
		MOCK_METHOD(void, fftwf_export_wisdom, (fftwf_write_char_func, void*));
		MOCK_METHOD(int, fftwf_import_system_wisdom, ());
		MOCK_METHOD(int, fftwf_import_wisdom_from_filename, (const  char*));
		MOCK_METHOD(int, fftwf_import_wisdom_from_file, (FILE*));
		MOCK_METHOD(int, fftwf_import_wisdom_from_string, (const  char*));
		MOCK_METHOD(int, fftwf_import_wisdom, (fftwf_read_char_func, void*));
		MOCK_METHOD(void, fftwf_fprint_plan, (const  fftwf_plan, FILE*));
		MOCK_METHOD(void, fftwf_print_plan, (const  fftwf_plan));
		MOCK_METHOD(char*, fftwf_sprint_plan, (const  fftwf_plan));
		MOCK_METHOD(void*, fftwf_malloc, (size_t));
		MOCK_METHOD(float*, fftwf_alloc_real, (size_t));
		MOCK_METHOD(fftwf_complex*, fftwf_alloc_complex, (size_t));
		MOCK_METHOD(void, fftwf_free, (void*));
		MOCK_METHOD(void, fftwf_flops, (const  fftwf_plan, double*, double*, double*));
		MOCK_METHOD(double, fftwf_estimate_cost, (const  fftwf_plan));
		MOCK_METHOD(double, fftwf_cost, (const  fftwf_plan));
		MOCK_METHOD(int, fftwf_alignment_of, (float*));


		static inline mock_fftwf* mock_ptr = nullptr;

		static void set_mock(mock_fftwf* p) { mock_ptr = p; }
		static mock_fftwf& mock_instance() { return *mock_ptr; }
	};

}