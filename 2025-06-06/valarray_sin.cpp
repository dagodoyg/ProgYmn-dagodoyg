#include <iostream>
#include <valarray>
#include <cmath>
#include <numeric>

int main(int argc, char **argv){
    int N=std::stoi(argv[1]);
    double interval=2.0*M_PI/(N-1);

    std::valarray<double> x(N);
    std::valarray<double> y(N);
    std::valarray<bool> aux1;

    std::iota(std::begin(x), std::end(x), 0);
    x *= interval;

    y = sin(x);
    
    aux1 = std::abs(y)<=0.5;
    int c = std::count(std::begin(aux1), std::end(aux1),true);

    std::valarray<double> aux2(c);
    aux2 = y[aux1];

    for(std::size_t n = 0; n < aux2.size(); ++n)
    std::cout << aux2[n] << ' ';
    std::cout << "\n";

    return 0;
}

//Godoy David
//