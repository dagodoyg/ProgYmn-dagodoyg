#include <iostream>
#include <cstdlib>
#include <string>

bool is_prime(int n);


int main(void){
    int lim_inf {1};
    int lim_sup {150};
    std::cout << "\033[32mLos numeros primos desde "<<lim_inf<<" hasta "<<lim_sup<< " son\033[0m\n" ;
    for (int ii=lim_inf;ii<=lim_sup;ii++){
        if( is_prime(ii) ){
            std::cout << "\033[35m" << ii << "\033[0m\n" ;
        }
    };
    return 0;
}



bool is_prime(int n){
 if(n<=1){ return false; }
 for(int ii=2;(ii*ii)<=n;ii++){
    if( n%ii==0 ){
        return false;
        } 
    }
    return true;
}

