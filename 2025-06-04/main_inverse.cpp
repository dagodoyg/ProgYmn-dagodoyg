#include "matrix_utils.h"

int main(void){

    std::vector<double> M1={2,1,5,3};
    matrix_printer(M1,2,2);
    std::vector<double> M2={3,-1,-5,2};
    matrix_printer(M2,2,2);
    std::vector<double> Z;
    matrix_multiply_AB(M1,M2,Z,2,2,2,2);

    matrix_printer(Z,2,2);
    
    std::cout << "----------------\n" 
        << "epsilon=0.1:  " << matrix_is_inverse(M1,M2,2,0.1) << "\n"
        << "epsilon=0.01:  " << matrix_is_inverse(M1,M2,2,0.01) << "\n";

    return 0;
}

//Salgado Benjamín
//Godoy Davidsss