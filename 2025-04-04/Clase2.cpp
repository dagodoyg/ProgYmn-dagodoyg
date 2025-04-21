#include <iostream>
#include <string>
int main(void) {
    std::cout << "Como te llamas?\n";
    std::string nombre; //declara la variable
    //std::cin >> nombre; solo lee hasta el primer espacio
    std::getline (std::cin, nombre); //lee completo
    std::cout << "Hola " + nombre + "\n";
    return 0;
}