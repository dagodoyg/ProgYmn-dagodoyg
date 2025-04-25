#include "prime_utils.h"
#include <iostream>

int main(int argc, char **argv){

    unsigned long long int num = std::stoull(argv[1]);
    unsigned long long int result {0};

    if (is_prime(num))
    {
        result=num;
    } else {
        for ( unsigned long long int ii = 2; ii<=std::sqrt(num); ii++)
        {
            if ( num%ii==0 ){
            if( is_prime(num/ii)){      
                result=num/ii;
                break;
            } 
            }
        }
    } 

    std::cout << result << "\n";
    return 0;
}
