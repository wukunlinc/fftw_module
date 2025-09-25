#pragma once
#include "gmock/gmock.h"
#include "fftw3.h"

namespace testing
{
	class mock_fftw
	{
	public:
		~mock_fftw() = default;

		MOCK_METHOD(void, fftw_execute, (const  fftw_plan));
		MOCK_METHOD(fftw_plan, fftw_plan_dft, (int, const  int*, fftw_complex*, fftw_complex*, int, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_1d, (int, fftw_complex*, fftw_complex*, int, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_2d, (int, int, fftw_complex*, fftw_complex*, int, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_3d, (int, int, int, fftw_complex*, fftw_complex*, int, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_many_dft, (int, const  int*, int, fftw_complex*, const  int*, int, int, fftw_complex*, const  int*, int, int, int, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru_dft, (int, const  fftw_iodim*, int, const  fftw_iodim*, fftw_complex*, fftw_complex*, int, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru_split_dft, (int, const  fftw_iodim*, int, const  fftw_iodim*, double*, double*, double*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru64_dft, (int, const  fftw_iodim64*, int, const  fftw_iodim64*, fftw_complex*, fftw_complex*, int, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru64_split_dft, (int, const  fftw_iodim64*, int, const  fftw_iodim64*, double*, double*, double*, double*, unsigned));
		MOCK_METHOD(void, fftw_execute_dft, (const  fftw_plan, fftw_complex*, fftw_complex*));
		MOCK_METHOD(void, fftw_execute_split_dft, (const  fftw_plan, double*, double*, double*, double*));
		MOCK_METHOD(fftw_plan, fftw_plan_many_dft_r2c, (int, const  int*, int, double*, const  int*, int, int, fftw_complex*, const  int*, int, int, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_r2c, (int, const  int*, double*, fftw_complex*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_r2c_1d, (int, double*, fftw_complex*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_r2c_2d, (int, int, double*, fftw_complex*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_r2c_3d, (int, int, int, double*, fftw_complex*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_many_dft_c2r, (int, const  int*, int, fftw_complex*, const  int*, int, int, double*, const  int*, int, int, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_c2r, (int, const  int*, fftw_complex*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_c2r_1d, (int, fftw_complex*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_c2r_2d, (int, int, fftw_complex*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_dft_c2r_3d, (int, int, int, fftw_complex*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru_dft_r2c, (int, const  fftw_iodim*, int, const  fftw_iodim*, double*, fftw_complex*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru_dft_c2r, (int, const  fftw_iodim*, int, const  fftw_iodim*, fftw_complex*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru_split_dft_r2c, (int, const  fftw_iodim*, int, const  fftw_iodim*, double*, double*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru_split_dft_c2r, (int, const  fftw_iodim*, int, const  fftw_iodim*, double*, double*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru64_dft_r2c, (int, const  fftw_iodim64*, int, const  fftw_iodim64*, double*, fftw_complex*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru64_dft_c2r, (int, const  fftw_iodim64*, int, const  fftw_iodim64*, fftw_complex*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru64_split_dft_r2c, (int, const  fftw_iodim64*, int, const  fftw_iodim64*, double*, double*, double*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru64_split_dft_c2r, (int, const  fftw_iodim64*, int, const  fftw_iodim64*, double*, double*, double*, unsigned));
		MOCK_METHOD(void, fftw_execute_dft_r2c, (const  fftw_plan, double*, fftw_complex*));
		MOCK_METHOD(void, fftw_execute_dft_c2r, (const  fftw_plan, fftw_complex*, double*));
		MOCK_METHOD(void, fftw_execute_split_dft_r2c, (const  fftw_plan, double*, double*, double*));
		MOCK_METHOD(void, fftw_execute_split_dft_c2r, (const  fftw_plan, double*, double*, double*));
		MOCK_METHOD(fftw_plan, fftw_plan_many_r2r, (int, const  int*, int, double*, const  int*, int, int, double*, const  int*, int, int, const  fftw_r2r_kind*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_r2r, (int, const  int*, double*, double*, const  fftw_r2r_kind*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_r2r_1d, (int, double*, double*, fftw_r2r_kind, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_r2r_2d, (int, int, double*, double*, fftw_r2r_kind, fftw_r2r_kind, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_r2r_3d, (int, int, int, double*, double*, fftw_r2r_kind, fftw_r2r_kind, fftw_r2r_kind, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru_r2r, (int, const  fftw_iodim*, int, const  fftw_iodim*, double*, double*, const  fftw_r2r_kind*, unsigned));
		MOCK_METHOD(fftw_plan, fftw_plan_guru64_r2r, (int, const  fftw_iodim64*, int, const  fftw_iodim64*, double*, double*, const  fftw_r2r_kind*, unsigned));
		MOCK_METHOD(void, fftw_execute_r2r, (const  fftw_plan, double*, double*));
		MOCK_METHOD(fftw_plan, fftw_copy_plan, (fftw_plan));
		MOCK_METHOD(void, fftw_destroy_plan, (fftw_plan));
		MOCK_METHOD(void, fftw_forget_wisdom, ());
		MOCK_METHOD(void, fftw_cleanup, ());
		MOCK_METHOD(void, fftw_set_timelimit, (double));
		MOCK_METHOD(void, fftw_plan_with_nthreads, (int));
		MOCK_METHOD(int, fftw_planner_nthreads, ());
		MOCK_METHOD(int, fftw_init_threads, ());
		MOCK_METHOD(void, fftw_cleanup_threads, ());
		MOCK_METHOD(void, fftw_threads_set_callback, ());
		MOCK_METHOD(void, fftw_make_planner_thread_safe, ());
		MOCK_METHOD(int, fftw_export_wisdom_to_filename, (const  char*));
		MOCK_METHOD(void, fftw_export_wisdom_to_file, (FILE*));
		MOCK_METHOD(char*, fftw_export_wisdom_to_string, ());
		MOCK_METHOD(void, fftw_export_wisdom, (fftw_write_char_func, void*));
		MOCK_METHOD(int, fftw_import_system_wisdom, ());
		MOCK_METHOD(int, fftw_import_wisdom_from_filename, (const  char*));
		MOCK_METHOD(int, fftw_import_wisdom_from_file, (FILE*));
		MOCK_METHOD(int, fftw_import_wisdom_from_string, (const  char*));
		MOCK_METHOD(int, fftw_import_wisdom, (fftw_read_char_func, void*));
		MOCK_METHOD(void, fftw_fprint_plan, (const  fftw_plan, FILE*));
		MOCK_METHOD(void, fftw_print_plan, (const  fftw_plan));
		MOCK_METHOD(char*, fftw_sprint_plan, (const  fftw_plan));
		MOCK_METHOD(void*, fftw_malloc, (size_t));
		MOCK_METHOD(double*, fftw_alloc_real, (size_t));
		MOCK_METHOD(fftw_complex*, fftw_alloc_complex, (size_t));
		MOCK_METHOD(void, fftw_free, (void*));
		MOCK_METHOD(void, fftw_flops, (const  fftw_plan, double*, double*, double*));
		MOCK_METHOD(double, fftw_estimate_cost, (const  fftw_plan));
		MOCK_METHOD(double, fftw_cost, (const  fftw_plan));
		MOCK_METHOD(int, fftw_alignment_of, (double*));


		static inline mock_fftw* mock_ptr = nullptr;

		static void set_mock(mock_fftw* p) { mock_ptr = p; }
		static mock_fftw& mock_instance() { return *mock_ptr; }
	};

}