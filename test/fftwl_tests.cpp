#include <array>
#include <complex>

#include "gtest/gtest.h"
#include "fftwl_mock_class.h"

import fftw_module;

using ::testing::_;
using ::testing::Eq;
using ::testing::InSequence;
using ::testing::Ne;
using ::testing::Return;

class FFTWLTest : public testing::Test
{
protected:
	FFTWLTest() :
		real_input(alloc_num),
		real_output(alloc_num),
		imag_input(alloc_num),
		imag_output(alloc_num),
		new_real_input(alloc_num),
		new_real_output(alloc_num),
		new_imag_input(alloc_num),
		new_imag_output(alloc_num),
		complex_input(alloc_num),
		complex_output(alloc_num),
		new_complex_input(alloc_num),
		new_complex_output(alloc_num)
	{
		testing::mock_fftwl::set_mock(&mock);
	}

	virtual ~FFTWLTest()
	{
		testing::mock_fftwl::set_mock(nullptr);
	}

	using test_type = long double;

	// Mock variables
	testing::mock_fftwl mock;
	static constexpr size_t alloc_num = 96;
	std::vector<test_type> real_input;
	std::vector<test_type> real_output;
	std::vector<test_type> imag_input;
	std::vector<test_type> imag_output;
	std::vector<test_type> new_real_input;
	std::vector<test_type> new_real_output;
	std::vector<test_type> new_imag_input;
	std::vector<test_type> new_imag_output;
	std::vector<std::complex<test_type>> complex_input;
	std::vector<std::complex<test_type>> complex_output;
	std::vector<std::complex<test_type>> new_complex_input;
	std::vector<std::complex<test_type>> new_complex_output;
	std::array<int, 3> extent{ 3, 6, 9 };
	std::array<int, 3> inembed{ 6, 6, 9 };
	std::array<int, 3> onembed{ 6, 9, 9 };
	std::array<fftw::guru_params, 3> rank_params{};
	std::array<fftw::guru_params, 3> batch_params{};
	int num_batches = 5;
	int input_stride = 2;
	int output_stride = 3;
	int input_dist = 4;
	int output_dist = 6;
	unsigned int flags = fftw::optimization::exhaustive | fftw::optimization::preserve_input;
	fftw::direction sign = fftw::direction::backward;
	std::vector<fftw::r2r_kind> kind = { fftw::r2r_kind::FFTW_HC2R, fftw::r2r_kind::FFTW_REDFT01, fftw::r2r_kind::FFTW_RODFT11 };
	fftwl_plan mock_plan = reinterpret_cast<fftwl_plan>(1);

	// Enforce call sequence
	InSequence s;
};

TEST_F(FFTWLTest, VectorCallsMallocAndFree)
{
	const size_t alloc_size = alloc_num * sizeof(test_type);

	EXPECT_CALL(mock, fftwl_malloc(alloc_size))
		.Times(1)
		.WillOnce(Return(real_input.data()));
	EXPECT_CALL(mock, fftwl_malloc(2 * alloc_size))
		.Times(1)
		.WillOnce(Return(complex_input.data()));
	EXPECT_CALL(mock, fftwl_free(complex_input.data())).Times(1);
	EXPECT_CALL(mock, fftwl_free(real_input.data())).Times(1);

	fftw::vector<test_type> vec(alloc_num);
	fftw::vector<std::complex<test_type>> vec_complex(alloc_num);
}

TEST_F(FFTWLTest, BasicInterfaceC2C)
{
	EXPECT_CALL(mock, fftwl_plan_many_dft(
		Eq(extent.size()), extent.data(), 1,
		reinterpret_cast<fftwl_complex*>(complex_input.data()), nullptr, 1, 1,
		reinterpret_cast<fftwl_complex*>(complex_output.data()), nullptr, 1, 1,
		static_cast<int>(sign), flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_dft(mock_plan,
		reinterpret_cast<fftwl_complex*>(new_complex_input.data()),
		reinterpret_cast<fftwl_complex*>(new_complex_output.data()))).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(extent, complex_input.data(), complex_output.data(), flags, sign);
	p.execute();
	p.execute(new_complex_input.data(), new_complex_output.data());
}

TEST_F(FFTWLTest, BasicInterfaceC2R)
{
	EXPECT_CALL(mock, fftwl_plan_many_dft_c2r(
		Eq(extent.size()), extent.data(), 1,
		reinterpret_cast<fftwl_complex*>(complex_input.data()), nullptr, 1, 1,
		real_output.data(), nullptr, 1, 1,
		flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_dft_c2r(mock_plan,
		reinterpret_cast<fftwl_complex*>(new_complex_input.data()),
		new_real_output.data())).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);


	fftw::plan p(extent, complex_input.data(), real_output.data(), flags);
	p.execute();
	p.execute(new_complex_input.data(), new_real_output.data());
}

TEST_F(FFTWLTest, BasicInterfaceR2C)
{
	EXPECT_CALL(mock, fftwl_plan_many_dft_r2c(
		Eq(extent.size()), extent.data(), 1,
		real_input.data(), nullptr, 1, 1,
		reinterpret_cast<fftwl_complex*>(complex_output.data()), nullptr, 1, 1,
		flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_dft_r2c(mock_plan,
		new_real_input.data(),
		reinterpret_cast<fftwl_complex*>(new_complex_output.data()))).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);


	fftw::plan p(extent, real_input.data(), complex_output.data(), flags);
	p.execute();
	p.execute(new_real_input.data(), new_complex_output.data());
}

TEST_F(FFTWLTest, BasicInterfaceR2R)
{
	EXPECT_CALL(mock, fftwl_plan_many_r2r(
		Eq(extent.size()), extent.data(), 1,
		real_input.data(), nullptr, 1, 1,
		real_output.data(), nullptr, 1, 1,
		kind.data(), flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_r2r(mock_plan,
		new_real_input.data(),
		new_real_output.data())).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);


	fftw::plan p(extent, real_input.data(), real_output.data(), flags, kind.data());
	p.execute();
	p.execute(new_real_input.data(), new_real_output.data());
}

TEST_F(FFTWLTest, AdvancedInterfaceC2C)
{
	EXPECT_CALL(mock, fftwl_plan_many_dft(
		Eq(extent.size()), extent.data(), num_batches,
		reinterpret_cast<fftwl_complex*>(complex_input.data()), inembed.data(), input_stride, input_dist,
		reinterpret_cast<fftwl_complex*>(complex_output.data()), onembed.data(), output_stride, output_dist,
		static_cast<int>(sign), flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_dft(mock_plan,
		reinterpret_cast<fftwl_complex*>(new_complex_input.data()),
		reinterpret_cast<fftwl_complex*>(new_complex_output.data()))).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(extent, num_batches,
		complex_input.data(), inembed.data(), input_stride, input_dist,
		complex_output.data(), onembed.data(), output_stride, output_dist,
		flags, sign);
	p.execute();
	p.execute(new_complex_input.data(), new_complex_output.data());
}

TEST_F(FFTWLTest, AdvancedInterfaceC2R)
{
	EXPECT_CALL(mock, fftwl_plan_many_dft_c2r(
		Eq(extent.size()), extent.data(), num_batches,
		reinterpret_cast<fftwl_complex*>(complex_input.data()), inembed.data(), input_stride, input_dist,
		real_output.data(), onembed.data(), output_stride, output_dist,
		flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_dft_c2r(mock_plan,
		reinterpret_cast<fftwl_complex*>(new_complex_input.data()),
		new_real_output.data())).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(extent, num_batches,
		complex_input.data(), inembed.data(), input_stride, input_dist,
		real_output.data(), onembed.data(), output_stride, output_dist,
		flags);
	p.execute();
	p.execute(new_complex_input.data(), new_real_output.data());
}

TEST_F(FFTWLTest, AdvancedInterfaceR2C)
{
	EXPECT_CALL(mock, fftwl_plan_many_dft_r2c(
		Eq(extent.size()), extent.data(), num_batches,
		real_input.data(), inembed.data(), input_stride, input_dist,
		reinterpret_cast<fftwl_complex*>(complex_output.data()), onembed.data(), output_stride, output_dist,
		flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_dft_r2c(mock_plan,
		new_real_input.data(),
		reinterpret_cast<fftwl_complex*>(new_complex_output.data()))).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(extent, num_batches,
		real_input.data(), inembed.data(), input_stride, input_dist,
		complex_output.data(), onembed.data(), output_stride, output_dist,
		flags);
	p.execute();
	p.execute(new_real_input.data(), new_complex_output.data());
}

TEST_F(FFTWLTest, AdvancedInterfaceR2R)
{
	EXPECT_CALL(mock, fftwl_plan_many_r2r(
		Eq(extent.size()), extent.data(), num_batches,
		real_input.data(), inembed.data(), input_stride, input_dist,
		real_output.data(), onembed.data(), output_stride, output_dist,
		kind.data(), flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_r2r(mock_plan,
		new_real_input.data(),
		new_real_output.data())).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(extent, num_batches,
		real_input.data(), inembed.data(), input_stride, input_dist,
		real_output.data(), onembed.data(), output_stride, output_dist,
		flags, kind.data());
	p.execute();
	p.execute(new_real_input.data(), new_real_output.data());
}

TEST_F(FFTWLTest, GuruInterfaceC2C)
{
	EXPECT_CALL(mock, fftwl_plan_guru64_dft(
		Eq(rank_params.size()), rank_params.data(), Eq(batch_params.size()), batch_params.data(),
		reinterpret_cast<fftwl_complex*>(complex_input.data()),
		reinterpret_cast<fftwl_complex*>(complex_output.data()),
		static_cast<int>(sign), flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_dft(mock_plan,
		reinterpret_cast<fftwl_complex*>(new_complex_input.data()),
		reinterpret_cast<fftwl_complex*>(new_complex_output.data()))).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(rank_params, batch_params, complex_input.data(), complex_output.data(), flags, sign);
	p.execute();
	p.execute(new_complex_input.data(), new_complex_output.data());
}

TEST_F(FFTWLTest, GuruInterfaceC2CSplit)
{
	EXPECT_CALL(mock, fftwl_plan_guru64_split_dft(
		Eq(rank_params.size()), rank_params.data(), Eq(batch_params.size()), batch_params.data(),
		real_input.data(), imag_input.data(), real_output.data(), imag_output.data(),
		flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_split_dft(mock_plan,
		new_real_input.data(), new_imag_input.data(), new_real_output.data(), new_imag_output.data())).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(rank_params, batch_params,
		real_input.data(), imag_input.data(), real_output.data(), imag_output.data(), flags);
	p.execute();
	p.execute(new_real_input.data(), new_imag_input.data(), new_real_output.data(), new_imag_output.data());
}

TEST_F(FFTWLTest, GuruInterfaceC2R)
{
	EXPECT_CALL(mock, fftwl_plan_guru64_dft_c2r(
		Eq(rank_params.size()), rank_params.data(), Eq(batch_params.size()), batch_params.data(),
		reinterpret_cast<fftwl_complex*>(complex_input.data()),
		real_output.data(),
		flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_dft_c2r(mock_plan,
		reinterpret_cast<fftwl_complex*>(new_complex_input.data()),
		new_real_output.data())).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(rank_params, batch_params, complex_input.data(), real_output.data(), flags);
	p.execute();
	p.execute(new_complex_input.data(), new_real_output.data());
}

TEST_F(FFTWLTest, GuruInterfaceC2RSplit)
{
	EXPECT_CALL(mock, fftwl_plan_guru64_split_dft_c2r(
		Eq(rank_params.size()), rank_params.data(), Eq(batch_params.size()), batch_params.data(),
		real_input.data(), imag_input.data(), real_output.data(),
		flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_split_dft_c2r(mock_plan,
		new_real_input.data(), new_imag_input.data(), new_real_output.data())).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(fftw::split::c2r(), rank_params, batch_params,
		real_input.data(), imag_input.data(), real_output.data(), flags);
	p.execute();
	p.execute(new_real_input.data(), new_imag_input.data(), new_real_output.data());
}

TEST_F(FFTWLTest, GuruInterfaceR2C)
{
	EXPECT_CALL(mock, fftwl_plan_guru64_dft_r2c(
		Eq(rank_params.size()), rank_params.data(), Eq(batch_params.size()), batch_params.data(),
		real_input.data(),
		reinterpret_cast<fftwl_complex*>(complex_output.data()),
		flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_dft_r2c(mock_plan,
		new_real_input.data(),
		reinterpret_cast<fftwl_complex*>(new_complex_output.data()))).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(rank_params, batch_params, real_input.data(), complex_output.data(), flags);
	p.execute();
	p.execute(new_real_input.data(), new_complex_output.data());
}

TEST_F(FFTWLTest, GuruInterfaceR2CSplit)
{
	EXPECT_CALL(mock, fftwl_plan_guru64_split_dft_r2c(
		Eq(rank_params.size()), rank_params.data(), Eq(batch_params.size()), batch_params.data(),
		real_input.data(), real_output.data(), imag_output.data(),
		flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_split_dft_r2c(mock_plan,
		new_real_input.data(), new_real_output.data(), new_imag_output.data())).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(fftw::split::r2c(), rank_params, batch_params,
		real_input.data(), real_output.data(), imag_output.data(), flags);
	p.execute();
	p.execute(new_real_input.data(), new_real_output.data(), new_imag_output.data());
}

TEST_F(FFTWLTest, GuruInterfaceR2R)
{
	EXPECT_CALL(mock, fftwl_plan_guru64_r2r(
		Eq(rank_params.size()), rank_params.data(), Eq(batch_params.size()), batch_params.data(),
		real_input.data(),
		real_output.data(),
		kind.data(), flags))
		.Times(1)
		.WillOnce(Return(mock_plan));
	EXPECT_CALL(mock, fftwl_execute(mock_plan)).Times(1);
	EXPECT_CALL(mock, fftwl_execute_r2r(mock_plan,
		new_real_input.data(),
		new_real_output.data())).Times(1);
	EXPECT_CALL(mock, fftwl_destroy_plan(mock_plan)).Times(1);

	fftw::plan p(rank_params, batch_params, real_input.data(), real_output.data(), flags, kind.data());
	p.execute();
	p.execute(new_real_input.data(), new_real_output.data());
}