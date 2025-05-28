#include "functions_arrays.h"
#include <fstream>

int main(int argc , char **argv){

    std::vector<double> u={1,3,4.5};

    std::cout.precision(16);

    std::vector<double> derivative=poly_deriv(u);

    for ( int jj = 0; jj < derivative.size(); jj++){
        std::cout << derivative[jj] << "\n";
    }

    std::cout << poly_evaluate(derivative,1) << "\n";

    std::ofstream file("derivatives.txt");

        file<<"x f derivative\n";

            for (double x = 0.1; x <= 10; x+=0.1){
                file << x << " " <<  poly_evaluate(u, x) << " " <<poly_evaluate(derivative, x) << "\n";
            }

    file.close();

    return 0;
}