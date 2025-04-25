#include "prime_utils.h"
#include <iostream>

int main(void){
    long lim_inf {300};
    long lim_sup {400-4};
    for (long ii=lim_inf;ii<=lim_sup;ii++){
        if( is_prime(ii) & is_prime(ii+4)){
            std::cout << "\033[32m( " << ii << " , " << ii+4 << " ) son cousin primes\033[0m \n" ;
        }
    };
    return 0;
}
