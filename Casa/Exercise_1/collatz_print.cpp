#include "functions.h"

int main(int argc, char **argv){
    long long int num = std::stoull(argv[1]);
    std::cout << great_collatz(num) << "\n" << number_collatz(num);
    return 0;
}