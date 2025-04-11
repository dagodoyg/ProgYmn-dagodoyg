#include <iostream>
#include <limits>
//para adivinar un número

//declaración
void play(void); 

int main (void){
    play();
    return 0;
}

//implementación
void play(void){
    const int numero=10; //const lo hace de solo lectura, no puede cambiar
    const int liminf=1;
    const int limsup=100;
    int lambda=numero+1;
    while(lambda!=numero){
    std::cout << "Adivina el numero entre " << liminf << " y " << limsup << "\n";
    std::cin >> lambda;
        if (lambda==numero)
        {
            std::cout << "Adivinaste\n";
            break;

        } else if ( std::cin.fail()){ //validación de la entrada
            std::cout << "No es un numero, ingrese una respuesta valida\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } else if ((lambda>limsup)||(lambda<liminf)) { //validación del rango
            std::cout << "Numero fuera del limite\n";

        } else if (lambda>numero) {
            std::cout << "Te pasaste\n";

        } else {
            std::cout << "Te quedaste corto\n";            
        }
    }
}