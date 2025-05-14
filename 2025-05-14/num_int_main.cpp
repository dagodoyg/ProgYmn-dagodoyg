#include "numerical_integral.h"
#include <cmath>
#include <fstream>
#include <vector>

double fun(double x);

int main(void){
    std::cout.setf(std::ios::scientific);
    std::cout.precision(16);
    double a{-1};
    double b{1};
    std::cout << "gauss_2: " << gauss_2(a,b,fun) << "\n";
    std::cout << "gauss_3: " << gauss_3(a,b,fun) << "\n";

    /*
    std::ofstream file("erf_data.txt");
    file << "N error\n";
    for (int N = 1; N <= 20; N++){
        double approx = romberg(0.0,1,N,fun);
        double error = std::abs(1.0-approx/(std::erf(1)));
        file << N << " " << error << "\n";
    }
    file.close();
    */

    return 0;
}

double fun(double x){
    return 7*x*x*x-8*x*x + 3*x +3;
}