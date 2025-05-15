#include "numerical_integral.h"
#include <cmath>
#include <fstream>
#include <vector>
#include <iomanip>

double fun(double x);

int main(void){
    std::cout.setf(std::ios::scientific);
    std::cout.precision(16);
    double a{0};
    double b{1};
    std::cout << "trapezoid: " << trapezoid(a,b,10,fun) << "\n";
    std::cout << "simpson: " << simpson(a,b,10,fun) << "\n";
    std::cout << "trapezoid+richardson: " << richardson(a,b,10,fun,trapezoid,2)<< "\n";
    std::cout << "simpson+richardson: " << richardson(a,b,10,fun,simpson,4)<< "\n";
    std::cout << "gauss_2: " << gauss_2(a,b,fun) << "\n";
    std::cout << "gauss_3: " << gauss_3(a,b,fun) << "\n";
    std::cout << "gauss_5: " << gauss_5(a,b,fun) << "\n";
    std::cout << "gauss_7: " << gauss_7(a,b,fun) << "\n";

    
    std::ofstream file("erf_data.txt");
    file << std::setprecision(8);
    file << "x trapezoid simpson traprich simprich gauss2 gauss3 gauss5 gauss7\n";
    for (double x = 0.1; x <= 10; x+=0.05){
        double exact=std::erf(x);
        file    << x << " "
                << std::abs(1-trapezoid(0,x,10,fun)/exact) << " "
                << std::abs(1-simpson(0,x,10,fun)/exact) << " "
                << std::abs(1-richardson(0,x,10,fun,trapezoid,2)/exact) << " "
                << std::abs(1-richardson(0,x,10,fun,simpson,4)/exact) << " "
                << std::abs(1-gauss_2(0,x,fun)/exact) << " "
                << std::abs(1-gauss_3(0,x,fun)/exact) << " "
                << std::abs(1-gauss_5(0,x,fun)/exact) << " "
                << std::abs(1-gauss_7(0,x,fun)/exact) << "\n";
    }
    file.close();
    

    return 0;
}

double fun(double x){
    const double factor = 2/std::sqrt(M_PI);
    return factor*std::exp(-x*x);
}