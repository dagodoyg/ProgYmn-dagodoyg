#include "functions_arrays.h"

int main(int argc , char **argv){

    std::vector<double> u={1,2,-10,3};

    std::cout.precision(16);

    std::vector<double> derivative=poly_deriv(u);
    for ( int jj = 0; jj < derivative.size(); jj++){
        std::cout << derivative[jj] << "\n";
    }

    return 0;
}