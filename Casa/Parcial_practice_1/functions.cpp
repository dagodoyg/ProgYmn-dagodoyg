#include "functions.h"

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

long long int sum_primes_lt(long long int n){
    long long int sum {0};
    for (long long int ii = 1; ii<n; ii++){
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

std::string four_digits(int num){
    std::string num_string = std::to_string(num);
    std::string digits_string = "";
    if (num<0){
        std::cerr << "Negative number, ignoring.";
    } else if (size(num_string)>4){
        std::cerr << "Number has more than 4 digits, ignoring.";
    } else {
        for(int ii = 1; ii<=4-size(num_string);ii++){
            digits_string = digits_string + "0" + " ";
        }
        for(int ii = 0; ii<=size(num_string)-1;ii++){
            digits_string = digits_string + num_string[ii] + " ";
        }
    }
    return digits_string;
}

void bab_sqrt(double num, int iter){
    double approx {num/2};

    for(int ii=0; ii<=iter; ii++){
        approx=0.5*(approx+num/approx);
    }

    std::cout << iter << "   " << approx << "\n";
}

int circ_uncertain(double radius , double uncert){
    double area = M_PI*radius*radius;
    double prop_uncert = 2*M_PI*radius*uncert;
    int counter {0};

    if (uncert==0){
        std::cout << area << "   " << "N.A." << "\n";
        return 0;
    }
    while ( floor(prop_uncert)==0 ){
       prop_uncert*=10;
       area*=10;
       counter++;
    }
 
    area = round(area)/pow( 10 , counter );
    prop_uncert = round(prop_uncert)/pow( 10 , counter );
    std::cout.precision(counter+1);
    std::cout << area << "   " << prop_uncert << "\n";
    return 0;
}

long long int smaller_prime(long long int num){
    
    if (num%2==0 && num!=2){
        num--;
    }
    
    while (is_prime(num)==false){
        num-=2;
    }
    
    return num;
}

long long int great_collatz(long long int num){
    long long int great_term {0};
    long long int aux {num};
    while (num>1){
        if (num%2==0){
            num=num/2;
        } else {
            num=3*num+1;
        }
        if (num>aux){
            aux=num;
        }  
    }
    return aux;
}

long long int number_collatz(long long int num){
    long long int length {1};
    while (num>1){
        if (num%2==0){
            num=num/2;
        } else {
            num=3*num+1;
        }
        length+=1;
    }
    return length;
}

void sexy_primes_lt_p(long long int num){
    if (num%2==0){
        num--;
    }

    for ( long int ii = num-6; ii >=5; ii-=2){
        if (is_prime(ii) && is_prime(ii+6)){
            std::cout << ii << "   " << ii+6 << "\n";
        }
    }
}

long long int nth_twin_primes(long long int num){

    long int counter {0};
    long int ii {3};
    long int aux {0};

    while (counter<num)
    {
        if (is_prime(ii) && is_prime(ii+2)){
            counter+=1;
            aux=ii;
        }
        ii+=2;
    }

    std::cout << "(" << aux << ", " << aux+2 << ")\n";
    return aux;
}