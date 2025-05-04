#include "derivadas.h"

double forward_diff(double x, double h,fptr f){
    return (f(x+h)-f(x))/h;
}

double central_diff(double x, double h,fptr f){
    return (f(x+h)-f(x-h))/(2*h);
}

double richardson(double x, double h, fptr f, algptr alg, int alpha){
    double precalc=std::pow(2.0,alpha);
    return (precalc*alg(x,h/2,f)-alg(x,h,f))/(precalc-1);
}
