#include "prime_utils.h"

int main(int argc, char **argv){
    long long int num = std::stoll(argv[1]);
    std::cout << "El multiplo de 3 y 5 mas grande menor o igual a "<<num<<" es "<<inferior_5_3_multiple(num) << "\n";
    return 0;
}
