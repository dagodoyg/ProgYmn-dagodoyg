#include "matrix_utils.h"

int main(void){

    std::vector<double> A(3*4,0.0);
    std::vector<double> B(4*3,0.0);
    std::vector<double> C(3*3,0.0);

    fill_matrix_random(A,3,4,2);
    fill_matrix_random(B,4,3,1);
    
    matrix_printer(A,3,4);
    std::cout << "----------\n";
    matrix_printer(B,4,3);
    std::cout << "----------\n";

    new_matrix_multiply_AB(A,B,C,3,4,4,3);
    matrix_printer(C,3,3);

    return 0;
}

//Salgado Benjamín
//Godoy David