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

long int argmax(const std::vector<double> & u){
    auto maxit = std::max_element(u.begin(),u.end());
    auto maxin = std::distance(u.begin(),maxit);

    return maxin;
}

long int argmin(const std::vector<double> & u){
    auto minit = std::min_element(u.begin(),u.end());
    auto minin = std::distance(u.begin(),minit);

    return minin;
}

double p_norm(const std::vector<double> & u, long long int p){
    double sum{0};
    
    for (auto val : u){
        sum+=std::pow(val,p);
    }

    return std::pow(sum,1.0/p);
}