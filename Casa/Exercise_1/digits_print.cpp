#include "functions.h"

int main(int argc, char **argv){
    long long int num = std::stoll(argv[1]);
    std::cout << four_digits (num) << "\n";
    return 0;
}

