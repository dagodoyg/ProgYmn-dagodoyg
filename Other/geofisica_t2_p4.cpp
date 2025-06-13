#include "numerical_integral.h"

double f(double x);

int main(void){
    double r_i = 11267.41651e3;
    double r_f = 6378e3;
    std::cout << gauss_7(r_i,r_f,f) << "\n";
}

double f(double x){
    const double G =  6.6743e-11;   // m^3/(kg s^2)
    const double M = 5.974e24; // kg
    const double coef = -1.0/std::sqrt(2.0*G*M); // s/m^{3/2}
    const double Rinv = 1.0/5.168e6; // 1/m

    return coef*( 1.0 / std::sqrt( (1.0/x) + Rinv) );
}