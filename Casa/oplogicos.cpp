#include <iostream>
int main(void){
    int a = 10, b = 20;
    bool result = false; 
    result = (a < b) && (3*a == b); // and , && , at value level
    std::cout << result << "\n"; 
    result = (a < b) || (3*a == b); // or, ||, at value level
    std::cout << result << "\n";
    int c = a & b; // at bits value
    std::cout << c << "\n";
    int d = a | b; // at bits value
    std::cout << d << "\n";
    return 0;
}
