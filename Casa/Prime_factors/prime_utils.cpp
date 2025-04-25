#include "prime_utils.h"

bool is_prime(unsigned long long int n){
 if(n<=1){ return false; }
 for(unsigned long long int ii=2;ii<=std::sqrt(n);ii++){
    if( n%ii==0 ){
        return false;
        } 
    }
    return true;
}
