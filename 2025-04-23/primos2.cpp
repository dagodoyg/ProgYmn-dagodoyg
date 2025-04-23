#include <iostream>
#include <cstdlib>

bool is_prime(long n);

int main(void){
    long lim_inf {500};
    long lim_sup {1234};
    long sum_primes {0};
    std::cout << "\033[32mLos numeros primos desde "<<lim_inf<<" hasta "<<lim_sup<< " son\033[35m\n" ;
    for (long ii=lim_inf;ii<=lim_sup;ii++){
        if( is_prime(ii) ){
            std::cout << ii << "\n" ;
            sum_primes=sum_primes+ii;
        }
    };
    std::cout << "\033[32mLa suma de los numeros primos entre " <<lim_inf<<" y "<<lim_sup << " es \033[35m"<< sum_primes<< "\033[0m\n";
    return 0;
}



bool is_prime(long n){
 if(n<=1){ return false; }
 for(long ii=2;(ii*ii)<=n;ii++){
    if( n%ii==0 ){
        return false;
        } 
    }
    return true;
}

