#include <iostream>
#include <eigen3/Eigen/Dense>

void filler(Eigen::MatrixXd & M1, Eigen::MatrixXd & M2, Eigen::MatrixXd & M3, double n, double R1, double R2, double d);

int main(void){
    double R1{10};
    double R2{-10};
    double d{1};

    Eigen::MatrixXd M1(2,2);
    Eigen::MatrixXd M2(2,2);
    Eigen::MatrixXd M3(2,2);
    Eigen::MatrixXd A(2,2);

    for (double n = 1.0; n <= 3.0; n+=0.5){
        filler(M1,M2,M3,n,R1,R2,d);
        A = M3*M2*M1;            
        std::cout << "refraction index: " << n << "\n"
            << "lense power: " << -A(0,1) << "\n"
            << "focal length: " << -1.0/A(0,1) << "\n"
            << "matrix determinant: " << A.determinant() << "\n"
            << "-------------------\n";
    }


    return 0;
}

void filler(Eigen::MatrixXd & M1, Eigen::MatrixXd & M2, Eigen::MatrixXd & M3, double n, double R1, double R2, double d){
    M1 << 1.0 , -(n-1.0)/R1,
        0.0 , 1.0;
    M2 << 1.0 , 0.0,
        d/n , 1.0;
    M3 << 1.0 , (n-1.0)/R2,
        0.0 , 1.0;
    return;
}
