#include "prime_utils.h"
#include <iostream>

int main(int argc, char **argv){
    unsigned long long int num = std::stoull(argv[1]);
    std::cout << great_prime_factor(num) << "\n";
    return 0;
}
