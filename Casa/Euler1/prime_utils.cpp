#include "prime_utils.h"

bool is_prime(long long int n){

 if(n<=1){ 
    return false; 
}

 for(long long int ii=2;ii<=std::sqrt(n);ii++){
    if( n%ii==0 ){
        return false;
        } 
    }
    return true;
}

long long int sum_primes_lt(long long int n){
    long long int sum {0};
    for (long long int ii = 1; ii<=n; ii++){
        if (is_prime(ii)){
            sum+=ii;
        }
    }
    return sum;
}

long long int great_prime_factor(long long int num){
    long long int result {0};
    long long int ii = 2;

    if (is_prime(num)){ 
        return num; 
    }

    for (long long int ii = 2; ii*ii<=num; ii++){
        while ( num%ii==0 ){  
            if ( is_prime(num/ii) ){
                    result=num/ii;
                    break;
                } else { 
                    num=num/ii;
                }
        } 
    }
    return result;
}

/*Nota: estoy consciente de que realmente no hemos visto el tipo de variable long long en clase (creo) pero 
unos de los casos de prueba del encabezado 1 y 2, dan lugar a valores que salen del rango de los long así que los dejé como long long
*/