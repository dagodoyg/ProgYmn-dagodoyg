#include <iostream>
//para adivinar un número
int main(void){
    const int numero=10; //const lo hace de solo lectura, no puede cambiar
    int lambda;
    for ( ; ; ){
    std::cout << "Adivina el numero entre 1 y 100:\n";
    std::cin >> lambda;
        if (lambda==numero)
        {
            std::cout << "Adivinaste\n";
            break;
        } else if (lambda>numero) {
            std::cout << "Te pasaste\n";
        //} 
        /*else if ((lambda>100)||(lambda<1)) {
            std::cout << "Numero invalido":
        }*/
        } else {
            std::cout << "Te quedaste corto\n";            
        }
    }
    return 0;
}