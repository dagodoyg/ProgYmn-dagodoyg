#include <iostream>
#include <cstdlib>

bool is_prime(long n);

int main(void){
    long lim_inf {1};
    long lim_sup {150};
    long sum_primes {0};
    for (long ii=lim_inf;ii<=lim_sup;ii++){
        if( is_prime(ii) ){
            sum_primes=sum_primes+ii;
        }
    };
    std::cout << "\033[32mLa suma de los numeros primos entre " <<lim_inf<<" y "<<lim_sup << " es \033[35m"<< sum_primes<< "\033[0m\n";
    return 0;
}
