#include "functions.h"

int main(int argc, char **argv){
    long long int num = std::stoull(argv[1]);
    std::cout << sum_primes_lt(num);
    return 0;
}