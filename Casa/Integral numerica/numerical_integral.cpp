#include "numerical_integral.h"

double trapezoid(double a, double b, int N, fptr fun){
    const double delta=(b-a)/N;
    double sum=(fun(a)+fun(b))*(delta/2);

    for(long int ii{1};ii<=N-1;ii++){
        sum+=delta*fun(a+ii*delta);
    }

    return sum;

}

double simpson(double a, double b, int N, fptr fun){
    if (N%2!=0){
        N++;
        std::cerr << "N debe ser par, usando N+1";
    }

    const double delta=(b-a)/N;
    double sum1=(fun(a)+fun(b))*(delta/3.0);
    double sum2{0};
    double sum3{0};

    for (long int ii{1}; ii <= N/2-1; ii++){
        sum2+=fun(a+2*ii*delta);
    }
    
    for (long int ii{1}; ii <= N/2; ii++){
        sum3+=fun(a+(2*ii-1)*delta);
    }

    return (sum1+(2.0*delta/3.0)*sum2+(4.0*delta/3.0)*sum3);

}

double romberg(double a, double b, int m, fptr fun){
    double array[m][m];

    for(int ii{0};ii<m;ii++){
        array[ii][0]=trapezoid(a,b,std::pow(2,ii),fun);
    }

    double precalc1{0};
    
    for (int kk{1}; kk <=m-1; kk++){ //columnas

        precalc1= std::pow(4,kk);

        for ( int jj{0}; jj<=m-1-kk; jj++){ //filas
            array[jj][kk]=(precalc1*array[jj+1][kk-1]-array[jj][kk-1])/(precalc1-1);
        }
        
    }
    
    return array[0][m-1];

}