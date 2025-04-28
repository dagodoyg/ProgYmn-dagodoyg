#include "functions.h"

int main(int argc, char **argv){
    std::cout.setf(std::ios::scientific);
    std::cout.precision(15);
    double num = std::stod(argv[1]);
    int iter = std::stoi(argv[2]);
    bab_sqrt(num,iter);
    return 0;
}

