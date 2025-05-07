#include "functions.h"

int main(int argc, char **argv){
    unsigned long long int num = std::stoull(argv[1]);
    std::cout << sec_great_prime_factor(num) << "\n";
    return 0;
}