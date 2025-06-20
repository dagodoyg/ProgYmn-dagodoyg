# include <iostream>
# include <eigen3/Eigen/Dense>


int main(int argc, char** argv)
{
   int N = std::stoi(argv[1]);

   Eigen::MatrixXd A = Eigen::MatrixXd::Random(N,N);
   Eigen::Vector3d b = Eigen::Vector3d::Random(N);
   //std::cout.precision(16);
   //std::cout.setf(std::ios::scientific);

   std::cout << "Here is the matrix A:\n" << A << std::endl;
   std::cout << "Here is the vector b:\n" << b << std::endl;
   Eigen::Vector3d x = A.colPivHouseholderQr().solve(b);
   std::cout << "The solution is:\n" << x << std::endl;
   std::cout << (A*x - b).norm() << "\n";

   return 0;
}