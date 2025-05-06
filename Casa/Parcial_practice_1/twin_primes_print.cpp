#include "functions.h"
#include <fstream>

int main(void){
    long long int y1{0};
    long long int y2{0};
    double result {0};

    std::ofstream file("norm.txt");
    

    file<<"x norm\n";
         
    
        for (int x = 1; x <= 100; x+=1)
        {
            y1=nth_twin_primes(x);
            y2=y1+2;
            result=std::sqrt(y1*y1+y2*y2);
            file << x << " "
                << result << "\n";
        }

    file.close();

    return 0;

}