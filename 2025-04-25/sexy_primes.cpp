#include <iostream>
#include <cstdlib>

bool is_prime(long n);

int main(int argc, char **argv){
    int lim_inf=std::stoi(argv[1]);
    int lim_sup=std::stoi(argv[2]);
    for (int ii=lim_inf;ii<=lim_sup-6;ii++){
        if( is_prime(ii) & is_prime(ii+6)){
            std::cout << "\033[32m( " << ii << " , " << ii+6 << " ) son dobletes sexy primes\033[0m \n" ;
        }
    };
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

