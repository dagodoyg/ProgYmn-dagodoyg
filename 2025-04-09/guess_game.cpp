#include <iostream>
//para adivinar un número
int main(void){
    const int numero=10; //const lo hace de solo lectura, no puede cambiar
    int lambda;
    std::cout << "Adivina el numero entre 1 y 100:\n";
    std::cin >> lambda;
        if (lambda==numero)
        {
            std::cout << "Adivinaste\n";
        } else {
            std::cout << "Intentalo denuevo\n";
            std::cin >> lambda;
        }
    return 0;
}