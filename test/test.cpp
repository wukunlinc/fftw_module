// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

import fftw_data_support;
import fftw_vector;
import fftw_module;
import std;



int main()
{
	//f::m::p ptest(1.f, 1.f);


    fftw::vector<double> v = { 1, 3, 5, 7, 23, 15, 87, 91};

    auto plan = fftw::fftw_plan_dft(1, nullptr, nullptr, nullptr, 1, 1);

    auto func = ::fftw_plan_dft;
    func(1, nullptr, nullptr, nullptr, 1, 1);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
