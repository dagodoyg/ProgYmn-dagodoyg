#include <iostream>
#include <cmath>
#include <vector>

void matrix_multiply_AB(const std::vector<double> A, const std::vector<double> B, std::vector<double> & C, const int Arows, const int Acols, const int Brows, const int Bcols);
std::vector<double> vector_rotate_3D(const std::vector<double> & u, const double thetax, const double thetay, const double thetaz);
void fill_matrix_Rx(std::vector<double> & Rx, const double thetax);
void fill_matrix_Ry(std::vector<double> & Ry, const double thetay);
void fill_matrix_Rz(std::vector<double> & Rz, const double thetaz);
void v_printer(const std::vector<double> & u);

int main(int argc, char **argv){
    std::vector<double> v(3,0.0);
    std::vector<double> u(3,0.0);
    v[0]=std::stod(argv[1]);
    v[1]=std::stod(argv[2]);
    v[2]=std::stod(argv[3]);
    double thetax = std::stod(argv[4]);
    double thetay = std::stod(argv[5]);
    double thetaz = std::stod(argv[6]);

    u = vector_rotate_3D(v,thetax,thetay,thetaz);

    std::cout << "Vector original:\n";
    v_printer(v);

    std::cout << "----------------------\n" << "Vector rotado:\n";
    v_printer(u);

    return 0;
}

void v_printer(const std::vector<double> & u){
    for (auto val : u){
        std::cout << val << "\n";
    }
}


void matrix_multiply_AB(const std::vector<double> A, const std::vector<double> B, std::vector<double> & C, const int Arows, const int Acols, const int Brows, const int Bcols){

    if (Acols!=Brows){
        std::cerr << "Invalid input\n";
        return;
    }
    
    C.resize(Arows*Bcols,0.0);

    for (int ii = 0; ii < Arows; ii++){

        for (int jj = 0; jj < Bcols; jj++){

            for (int kk = 0; kk < Acols; kk++){

                C[ii*Bcols + jj] += A[ii*Acols + kk] * B[kk*Bcols + jj];

            }
            
        }

    }
}


std::vector<double> vector_rotate_3D(const std::vector<double> & u, const double thetax, const double thetay, const double thetaz){

    std::vector<double> Rx(9,0.0);
    std::vector<double> Ry(9,0.0);
    std::vector<double> Rz(9,0.0);
    std::vector<double> rotated(3,0.0);
    std::vector<double> aux1(9,0.0);
    std::vector<double> aux2(9,0.0);

    fill_matrix_Rx(Rx,thetax);
    fill_matrix_Ry(Ry,thetay);
    fill_matrix_Rz(Rz,thetaz);

    matrix_multiply_AB(Ry,Rx,aux1,3,3,3,3);
    matrix_multiply_AB(Rz,aux1,aux2,3,3,3,3);
    matrix_multiply_AB(aux2,u,rotated,3,3,3,1);

    return rotated;

}

void fill_matrix_Rx(std::vector<double> & Rx, const double thetax){
    Rx[0] = 1;
    Rx[1*3 + 1] = std::cos(thetax);
    Rx[2*3 + 2] = std::cos(thetax);
    Rx[1*3 + 2] = -std::sin(thetax);
    Rx[2*3 + 1] = std::sin(thetax);
}

void fill_matrix_Ry(std::vector<double> & Ry, const double thetay){
    Ry[0] = std::cos(thetay);
    Ry[0*3 + 2] = std::sin(thetay);
    Ry[1*3 + 1] = 1;
    Ry[2*3 + 0] = -std::sin(thetay);
    Ry[2*3 + 2] = std::cos(thetay);
}

void fill_matrix_Rz(std::vector<double> & Rz, const double thetaz){
    Rz[0] = std::cos(thetaz);
    Rz[0*3 + 1] = -std::sin(thetaz);
    Rz[1*3 + 0] = std::sin(thetaz);
    Rz[1*3 + 1] = std::cos(thetaz);
    Rz[2*3 + 2] = 1;
}