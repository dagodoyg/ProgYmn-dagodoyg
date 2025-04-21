#include <iostream>

int main(void){
int a = 10, b = 20, c = 0; 
a = b; // assigns b value to a value
std::cout << "a1= "<< a << "\n";
a = b + 60; // adds 60 to b value, then assigns that value to a
std::cout << "a2= "<< a << "\n";
a += 60; // same as previous
std::cout << "a3= "<< a << "\n";
a = 2*b; // multiplication. Here same as a *= b;
std::cout << "a4= "<< a << "\n";
a = b/3; // division, notice truncation for integers. a /= 3;
std::cout << "a5= "<< a << "\n";
a = b%7; // modulo operator, residue
std::cout << "a6= "<< a << "\n";
a = 10;
b = 20; 
a = b++; // post increment
std::cout << "a7= "<< a << "\n";
a = 10;
b = 20; 
a = ++b; // pre increment
std::cout << "a8= "<< a << "\n";
return 0;
}