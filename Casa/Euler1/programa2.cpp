#include "functions.h"

int main(int argc, char **argv){
    long long int num = std::stoll(argv[1]);
    std::cout << "El factor primo mas grande de "<< num <<" es " << great_prime_factor(num) << "\n";
    return 0;
}


/*Nota:
unos de los casos de prueba del encabezado 1 y 2, dan lugar a valores que salen del rango de los long así que los dejé como long long
*/