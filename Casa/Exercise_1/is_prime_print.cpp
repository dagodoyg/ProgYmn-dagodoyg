#include "functions.h"

int main(int argc, char **argv){
    unsigned long long int num = std::stoull(argv[1]);
    std::cout << is_prime(num);
    return 0;
}