#include "prime_utils.h"
#include <iostream>

int main(int argc, char **argv){

    long int num = std::stol(argv[1]);
    long int result {0};
    for(long ii=num;ii>1;ii--){
        if(num%ii==0 && is_prime(ii)){
            result=ii;
            break;
        }
    }
    std::cout << result << "\n";
    return 0;
}
