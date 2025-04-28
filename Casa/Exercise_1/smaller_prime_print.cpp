#include "functions.h"

int main(int argc, char **argv){
    long long int num = std::stoull(argv[1]);
    std::cout << smaller_prime(num);
    return 0;
}