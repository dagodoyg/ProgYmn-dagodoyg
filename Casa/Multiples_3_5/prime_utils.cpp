#include "prime_utils.h"

bool is_prime(long long int n){
 if(n<=1){ return false;
           std::cerr << "\nEntrada no valida\n";}
 for(long long int ii=2;ii<=std::sqrt(n);ii++){
    if( n%ii==0 ){
        return false;
        } 
    }
    return true;
}

long long int great_prime_factor(long long int num){
    long long int result {0};
    if (num<=1)
    {
        std::cerr << "\nEntrada no valida\n";
        return 0;
    }
    
    
    if (is_prime(num))
    {
        result=num;
    } else {
        for ( long long int ii = 2; ii<=std::sqrt(num); ii++)
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

long long int inferior_5_3_multiple(long long int num){
    long long int result{0};

    if (num<=1)
    {
        std::cerr << "\nEntrada no valida\n";
        return 0;
    }

    if ( num%3==0 && num%5==0)
    {
        result=num;
    } else {
        while (num%3!=0 || num%5!=0 ){
            num-=1;
        }
        result=num;
    }
    return result;
}