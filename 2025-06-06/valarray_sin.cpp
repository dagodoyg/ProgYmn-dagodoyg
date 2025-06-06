#include <iostream>
#include <valarray>
#include <cmath>
#include <numeric>

int main(int argc, char **argv){
    int N=std::stoi(argv[1]);
    double interval=2.0*M_PI/(N-1);

    std::valarray<double> x(N);
    std::valarray<double> y(N);

    std::iota(std::begin(x), std::end(x), 0);
    x *= interval;

    y = sin(x);

    std::valarray<double> aux = x[std::abs(y) <= 0.5];

    for(std::size_t n = 0; n < aux.size(); ++n)
    std::cout << aux[n] << ' ';
    std::cout << "\n";

    return 0;
}

//Godoy David
//