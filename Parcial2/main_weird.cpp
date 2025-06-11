#include <iostream>
#include <cmath>
#include <vector>

void new_matrix_multiply_AB(const std::vector<double> A, const std::vector<double> B, std::vector<double> & C, const int Arows, const int Acols, const int Brows, const int Bcols);
double matrix_trace(const std::vector<double> & M, const int n);
void matrix_transpose(const std::vector<double> & M, const int m, const int n,std::vector<double> & Z);
void fill_matrix_weird(std::vector<double> & A, const int n);
double operate(int n);


int main(void){
    std::cout << operate(50) << "\n";    
}


void new_matrix_multiply_AB(const std::vector<double> A, const std::vector<double> B, std::vector<double> & C, const int Arows, const int Acols, const int Brows, const int Bcols){

    if (Acols!=Brows){
        std::cerr << "Invalid input\n";
        return;
    }
    
    C.resize(Arows*Bcols, 0.0);

    for (int ii = 0; ii < Arows; ii++){

        for (int jj = 0; jj < Bcols; jj++){

            C[ii*Bcols + jj] = 0;

            for (int kk = 0; kk < Acols; kk++){

                C[ii*Bcols + jj] += A[ii*Acols + kk] * B[kk*Bcols + jj];

            }
            
        }

    }
}


double matrix_trace(const std::vector<double> & M, const int n){
    double sum{0};

    if (n*n!=M.size()){
        std::cerr << "Invalid input\n";
        return 0;
    }
    
    for (int ii{0}; ii < n; ii++){
        sum+=M[ii*n+ii];
    }
    
    return sum;
}

void matrix_transpose(const std::vector<double> & M, const int m, const int n,std::vector<double> & Z){
    for (int ii = 0; ii < m; ii++){
        for (int jj = 0; jj < n; jj++){
            Z[jj*m + ii] = M[ii*n + jj];
        }
    }  
}

void fill_matrix_weird(std::vector<double> & A, const int n){
    A.resize(n*n,0.0);
    for (int ii{0}; ii < n; ii++){
        for (int jj{0}; jj < n; jj++){
            A[ii*n + jj] = 0.0;
            
            if (ii==jj){
                A[ii*n + jj]+=(ii*ii)/(jj+1.0);
            }
            if (ii==(jj+1)){
                A[ii*n + jj]+=std::sin(2*ii-1.0);
            }
            if ((ii+1)==jj){
                A[ii*n + jj]+=std::log( (jj*jj+2.0*jj) );
            }
        }
    }
}

double operate(int n){
    std::vector<double> A(n*n,0.0);
    std::vector<double> A_T(n*n,0.0);
    std::vector<double> Z;

    fill_matrix_weird(A,n);

    matrix_transpose(A,n,n,A_T);

    new_matrix_multiply_AB(A_T,A,Z,n,n,n,n);
    
    return matrix_trace(Z,n);
}



