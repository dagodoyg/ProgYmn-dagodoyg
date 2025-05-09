#include "numerical_integral.h"

double trapezoid(double a, double b, int N, fptr fun){
    const double delta=(b-a)/N;
    double sum=(fun(a)+fun(b))*(delta/2);

    for(long int ii{1};ii<=N-1;ii++){
        sum+=delta*fun(a+ii*delta);
    }

    return sum;

}