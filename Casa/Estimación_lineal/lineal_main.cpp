#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <iomanip>
#include <fstream>

double Ex(const std::vector<double> x);
double Exy(const std::vector<double> x, const std::vector<double> y);
std::array<double, 4> lineal_regression(const std::vector<double> x, const std::vector<double> y);


int main(int argc , char **argv){


    std::ifstream file(argv[1]);

    std::vector<double> x,y;
    double xi,yi;

    while (file >> xi >> yi) {
        x.push_back(xi);
        y.push_back(yi);
    }

    file.close();

    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    //se toma la regresión
    std::array<double, 4> result = lineal_regression(x,y);

    //se imprimen los coeficientes
    std::cout << "m\tb\tdm\tdb\n";

    for (auto coef : result){
        std::cout << coef << "\t";
    }

    std::cout << "\n";

    //se compara la pendiente con el valor teórico
    double mexpected = (6.62607015e-34)/(1.602176634e-19);
    std::cout << "------------------------\nValor esperado m: " 
        << mexpected << "\t Error relativo: " << std::abs(1-result[0]/mexpected) << "\n";

    return 0;
}

double Ex(const std::vector<double> x){

    double sum{0};

    for(auto value : x){
        sum+=value;
    }

    return sum/x.size();
}

double Exy(const std::vector<double> x, const std::vector<double> y){

    double sum{0};

    if (x.size()!=y.size()){
        std::cerr << "Los vectores deben tener el mismo tamaño\n";
        return 0;
    }

    for(long long int ii{0}; ii < x.size(); ii++){
        sum+=x[ii]*y[ii];
    }

    return sum/x.size();
}

std::array<double, 4> lineal_regression(const std::vector<double> x, const std::vector<double> y){

    std::array<double, 4> c = {0,0,0,0};
    
    if (x.size()!=y.size()){
        std::cerr << "Los vectores deben tener el mismo tamaño\n";
        return c;
    }

    //calculos previos
    double X = Ex(x);
    double Y = Ex(y);
    double XX = Exy(x,x);
    double YY = Exy(y,y);
    double XY = Exy(x,y);
    double precalc = XX - X*X; 
    long long int N = x.size();

    //coeficientes
    double m = ( XY - X*Y ) / precalc ;
    double b = ( XX * Y - X*XY ) / precalc ;
    double s2 = N / ( N - 2.0 ) * ( YY - Y*Y - m*m*precalc );
    double dm = std::sqrt( s2 / ( N * precalc ) );
    double db = std::sqrt( dm*dm*XX );

    //se guardan en un vector para devolverlos
    c = { m , b , dm , db};

    return c;
}