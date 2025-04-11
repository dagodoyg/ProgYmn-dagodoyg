#include <iostream>
#include <limits>
#include <cstdlib>
#include <random>
//para adivinar un número

//declaración
void play(int min_value, int max_value);

int main (void){
    play(1,100);
    play (1,100);
    return 0;
}

//implementación
void play(int min_value,int max_value){
    std::cout << "Que comience el juego\n";
    //int seed=rand();
    //const int numero=min_value+(rand() % (max_value-min_value+1)); //const lo hace de solo lectura, no puede cambiar ; numero aleatorio
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int>distro(min_value,max_value);
    const int numero=distro(gen);
    const int liminf=min_value;
    const int limsup=max_value;
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