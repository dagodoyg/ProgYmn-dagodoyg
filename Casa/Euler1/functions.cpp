#include "functions.h"

bool is_prime(long long int n){

    if(n<=1){ 
        return false; 
    } else if (n%2==0 && n!=2){
        return false;
    }
    
    for(long long int ii=3;ii<=sqrt(n);ii+=2){
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
    long long int ii {2};

    if (is_prime(num)){ 
        return num; 
    }

    while (ii*ii<=num){
        result=num/ii;
        if ( num%ii!=0 ){
            ii++;
            continue;
        } else if(is_prime(result)){
            break;
        }
        num=result;
    }

    return result;
}

/*Nota:
unos de los casos de prueba del encabezado 1 y 2, dan lugar a valores que salen del rango de los long así que los dejé como long long
*/

long int sum_fibonacci_odd(long int num){ 
    long int ahead{1};
    long int behind{1};
    long int aux{0};
    long int sum{0};
    while (ahead<=num)
    {
        if (ahead%2!=0){
            sum+=ahead;
        }
        aux=behind;
        behind=ahead;
        ahead+=aux;
    }
    return sum;
    
}