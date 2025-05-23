#include <iostream>
#include <vector>
#include <algorithm>


int main(void){
    std::vector<int> x;
    x.resize(5,0);
    x={2, 3, 4, 5, 6};

    std::cout << &x[0] << "\n";

    x.push_back(10);

    std::cout << &x[0] << "\n";

    auto print =[](double x){
        std::cout << x << "\n";
    };
    std::for_each(x.begin(), x.end(), print);

    return 0;  
}

//David Godoy
//Tomas Jaramillo
//Tomas Aparicio