#include <iostream>
#include <cmath>
#include <fstream>

bool is_prime( unsigned long long int n);
long long int great_prime_factor(long long int num);
long long int second_largest_prime_factor(long long int num);

int main(void){
    std::ofstream file("prime2.txt");

    file<<"x prime2\n";

    for (long int x{2}; x <= 200; x+=1){
        file << x << " " << second_largest_prime_factor(x) << "\n"; 
    }

    file.close();
    return 0;
    
}

bool is_prime( unsigned long long int n){

    if(n<=1){ 
        return false; 
    } else if (n%2==0 && n!=2){
        return false;
    }
    
    for(unsigned long long int ii=3;ii<=sqrt(n);ii+=2){
        if( n%ii==0 ){
            return false;
        } 
    }

    return true;
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

long long int second_largest_prime_factor(long long int num){
    long long int result {0};
    long long int aux {0};

    if (is_prime(num)){ 
        std::cout << "el numero es primo, no hay mas factores primos\n";
        return num; 
    }
    aux=num/great_prime_factor(num);
    result=great_prime_factor(aux);
    return result;
}