#include "functions.h"

int main(int argc, char **argv){
    long long int num = std::stoull(argv[1]);
    sexy_primes_lt_p(num);
    return 0;
}