#include "Integrar_datos.h"

std::vector<double> trapezoid_acumulative(std::vector<double> x,std::vector<double> y){
    int n = x.size();
    std::vector<double> result(n);
    double dx{0};
    result[0]=0;
    for(int ii{1}; ii < n; ii++){
        dx=x[ii]-x[ii-1];
        result[ii]=result[ii-1]+(dx/2)*(y[ii]+y[ii-1]);
    }
    return result;
}