#include "prime_utils.h"

int main(int argc, char **argv){
    long long int num = std::stoll(argv[1]);
    std::cout << "El factor primo mas grande de "<< num <<" es " << great_prime_factor(num) << "\n";
    return 0;
}


/*Nota: estoy consciente de que realmente no hemos visto el tipo de variable long long en clase (creo) pero 
uno de los casos de prueba del encabezado, 600851475243, se sale del rango de los long así que lo dejé como long long
*/