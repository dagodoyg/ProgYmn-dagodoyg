#include <cmath>
#include <iostream>
#include <functional>
#include <vector>
#include <fstream>

double f(double x,double alpha, double beta);
double xq(double q, double alpha, double beta);

using fptr = std::function<double(double)>;
double gauss_7(double a, double b, fptr fun);
double newton_root(double q, double alpha, double beta,double epsilon);

int main(void){
    std::cout << newton_root(0.5,1.0,1.0,1e-6) << "\n";
}

double f(double x, double alpha, double beta){
    return std::exp(-x/beta) * (1.0 / (std::pow(beta,alpha) * std::tgamma (alpha)) ) * std::pow(x,alpha-1.0);
}

double xq(double q, double alpha, double beta){
    double y{0};

    auto fun = [alpha,beta](double x){
        return f(x,alpha,beta);
    };

    double z=gauss_7(0,y,fun);

    while (z<q){
        y+=1e-6;
        z=gauss_7(0,y,fun);
    }

    return y;
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

double newton_root(double q, double alpha, double beta,double epsilon){
    double behind = 1;
    double ahead = behind;
    double aux{0};

    auto fun = [alpha,beta](double x){
        return f(x,alpha,beta);
    };

    do
    {
        aux=ahead;
        ahead = behind - gauss_7(0,behind,fun)/fun(behind);
        behind = aux;
    } while (std::abs(ahead-behind)>epsilon);
    

    return ahead;
}