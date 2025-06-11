#include <iostream>
#include <valarray>
#include <random>
#include <cmath>
#include <numeric>

double mean_field(int n, int seed);


int main(void){                       
    std::cout << mean_field(1000,42) << "\n";
    
    return 0;
}

double mean_field(int n, int seed){
    std::mt19937 gen(seed);                         
    std::uniform_real_distribution<> distrib(-5.0, 5.0);

    std::valarray<double> x(0.0,n);
    std::valarray<double> y(0.0,n);

    for (int i = 0; i < n; ++i){
        x[i] = distrib(gen);
        y[i] = distrib(gen);
    }

    std::valarray<double> Vx = x*x-y*y;
    std::valarray<double> Vy = 2*x*y;
    
    std::valarray<double> norm = std::sqrt(Vx*Vx + Vy*Vy);
    return norm.sum()/n;
}

