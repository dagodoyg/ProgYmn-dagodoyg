#include "functions.h"

int main(int argc, char **argv){
    long long int num = std::stoll(argv[1]);
    std::cout << "La suma de los terminos de fibonacci impares menores o iguales a "<< num <<" es " << sum_fibonacci_odd(num) << "\n";
    return 0;
}

/*Nota:
unos de los casos de prueba del encabezado 1 y 2, dan lugar a valores que salen del rango de los long así que los dejé como long long
*/