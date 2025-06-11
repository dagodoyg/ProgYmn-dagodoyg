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

double richardson(double a, double b, int N, fptr f, algptr alg, int alpha){
    double aux = std::pow(2.0, alpha);
    double val1 = alg(a, b, N, f);
    double val2 = alg(a, b, 2*N, f);
    return (aux*val2 - val1)/(aux - 1.0);
}

double gauss_2(double a, double b, fptr fun){
    double x0=1/sqrt(3);
    double w0=1;
    double m = (b-a)/2;
    double c = (b+a)/2;
    double result=w0*fun(m*x0+c)+w0*fun(-m*x0+c);
    return result*m;
}

double gauss_3(double a, double b, fptr fun){
    double x0=-std::sqrt(3.0/5.0);
    double w0=5.0/9.0;
    
    double x1=0;
    double w1=8.0/9.0;

    double x2=std::sqrt(3.0/5.0);
    double w2=5.0/9.0;

    double m = (b-a)/2;
    double c = (b+a)/2;

    double result=w0*fun(m*x0+c)+w1*fun(m*x1+c)+w2*fun(m*x2+c);
    return result*m;
}

double gauss_5(double a, double b, fptr fun){
    std::vector<double> x(5);
    std::vector<double> w(5);
    double result{0};

    x[0]=-(1.0/3.0)*std::sqrt(5.0+2.0*std::sqrt(10.0/7.0));
    x[1]=-(1.0/3.0)*std::sqrt(5.0-2.0*std::sqrt(10.0/7.0));
    x[2]=0;
    x[3]=(1.0/3.0)*std::sqrt(5.0-2.0*std::sqrt(10.0/7.0));
    x[4]=(1.0/3.0)*std::sqrt(5.0+2.0*std::sqrt(10.0/7.0));

    w[0]=(322.0-13.0*std::sqrt(70))/900.0;
    w[1]=(322.0+13.0*std::sqrt(70))/900.0;
    w[2]=128.0/225.0;
    w[3]=(322.0+13.0*std::sqrt(70))/900.0;
    w[4]=(322.0-13.0*std::sqrt(70))/900.0;

    double m = (b-a)/2;
    double c = (b+a)/2;

    for(int ii{0};ii<=4;ii++){
        result+=w[ii]*fun(m*x[ii]+c);
    }

    return m*result;
}

double gauss_7(double a, double b, fptr fun){
    std::vector<double> x(7);
    std::vector<double> w(7);
    double result{0};

    x[0]=0;
    x[1]=0.4058451513773972;
    x[2]=-0.4058451513773972;
    x[3]=-0.7415311855993945;
    x[4]=0.7415311855993945;
    x[5]=-0.9491079123427585;
    x[6]=0.9491079123427585;

    w[0]=0.4179591836734694;
    w[1]=0.3818300505051189;
    w[2]=0.3818300505051189;
    w[3]=0.2797053914892766;
    w[4]=0.2797053914892766;
    w[5]=0.1294849661688697;
    w[6]=0.1294849661688697;

    double m = (b-a)/2;
    double c = (b+a)/2;

    for(int ii{0};ii<=6;ii++){
        result+=w[ii]*fun(m*x[ii]+c);
    }

    return m*result;
}