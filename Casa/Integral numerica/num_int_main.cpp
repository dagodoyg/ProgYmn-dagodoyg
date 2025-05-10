#include "numerical_integral.h"
#include <cmath>
#include <fstream>
#include <vector>

double fun(double x);

int main(void){
    //std::cout << romberg(0,1,2,fun) << "\n";
    //std::cout << trapezoid(0,1,1,fun) << "\n";
    //std::cout << trapezoid(0,1,2,fun) << "\n";

    std::ofstream file("erf_data.txt");
    file << "N error\n";
    for (int N = 1; N <= 20; N++){
        double approx = romberg(0.0,1,N,fun);
        double error = std::abs(1.0-approx/(std::erf(1)));
        file << N << " " << error << "\n";
    }
    file.close();

    return 0;
}

double fun(double x){
    const double factor = 2/std::sqrt(M_PI);
    return factor*std::exp(-x*x);
}