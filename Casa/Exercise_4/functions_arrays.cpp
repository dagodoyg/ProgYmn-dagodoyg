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

double median(std::vector<double> u){

    std::sort(u.begin(),u.end());
    long long int N=u.size();
    double result{0};

    if (N%2!=0){
        result = u[ ( (N+1)/2 ) - 1 ];
    } else {
        result = ( u[ (N/2) - 1 ] + u[ (N/2) ] ) / 2.0;
    }
    
    return result;
}   

double percentil(std::vector<double> u, double i){

    std::sort(u.begin(),u.end());

    long long int N = u.size();
    double aux = (N*i)/100.0;
    double E{0};
    double result{0};

    double D = std::modf(aux, &E);
    long long int index = static_cast<long long int>(E);

    if (D==0){
        result = (u[E-1] + u[E]) / 2.0;
    } else {
        result = u[E];
    }
    
    return result;
}

void fill_randomly(std::vector<double> & u){
    srand(time(0));
    long long int N=u.size();

    for (long long int ii{0}; ii<N; ii++){
        u[ii]=rand();
    }
}

void v_printer(const std::vector<double> & u){
    for (auto val : u){
        std::cout << val << "\n";
    }
}