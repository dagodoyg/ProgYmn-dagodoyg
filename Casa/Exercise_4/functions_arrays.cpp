#include "functions_arrays.h"

double vector_norm(std::vector<double> v){
    double sum{0};

    for (auto val : v){
        sum+=val*val;
    }
    
    return std::sqrt(sum);
}

std::vector<double> poly_deriv(std::vector<double> v){
    for ( long int ii{0}; ii < v.size(); ii++){
        v[ii]*=ii;
    }

    v.erase(v.begin());

    return v;
}