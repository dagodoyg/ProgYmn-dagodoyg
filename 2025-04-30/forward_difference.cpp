#include "derivadas.h"

double f(double x);

int main(void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    double x {1.234};
    double h {1.0e-10};

    double forward = forward_diff(x,h,f);
    double central = central_diff(x,h,f);
    double exact = 2*x*cos(x*x);

    std::cout << forward << "\n";
    std::cout << central << "\n";
    std::cout << exact << "\n";
    std::cout << std::abs(1-forward/exact) << "   " << std::abs(1-central/exact) << "\n";
}

double f(double x){
    return std::sin(x*x);
}