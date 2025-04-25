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

unsigned long long int great_prime_factor(unsigned long long int num){
    unsigned long long int result {0};
    if (is_prime(num))
    {
        result=num;
    } else {
        for ( unsigned long long int ii = 2; ii<=std::sqrt(num); ii++)
        {
            while ( num%ii==0 ){  
                if ( is_prime(num/ii) ){
                    result=num/ii;
                    break;
                } else { num=num/ii; }
            } 
        }
    }
    return result;
}