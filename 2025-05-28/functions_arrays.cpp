#include "functions_arrays.h"

std::vector<double> poly_deriv(std::vector<double> v){

    for ( long int ii{0}; ii < v.size(); ii++){
        v[ii]*=ii;
    }

    v.erase(v.begin());

    return v;
}

double poly_evaluate(std::vector<double> v, double x){
    double result{0};

     for ( long int ii{0}; ii < v.size(); ii++){
        result+=v[ii]*std::pow(x,ii);
    }

    return result;
}