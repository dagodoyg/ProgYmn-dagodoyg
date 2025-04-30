#include "derivadas.h"

double f(double x);

int main(void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    double x {1.234};
    double h {1.0e-10};

    std::cout << forward_diff(x,h,f) << "\n";
    std::cout << central_diff(x,h,f) << "\n";
    std::cout << 2*x*cos(x*x) << "\n";
}

double f(double x){
    return std::sin(x*x);
}