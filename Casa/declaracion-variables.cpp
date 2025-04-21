#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main(void){
    int entero;
    double decimal=-9.87*std::pow(10, -8);
    std::string nombre = "David";
    std::vector<double> v(10); //no le gusta como lo inicializo pero funciona y no es incorrecto, todos los elementos son 0.0
    std::cout << decimal << "\n" << nombre << "\n" << v[1]; //el error aparece aqui porque el vector no fué inicializado 
                                                            //y podría dar problemas en otro caso, aunque funciona en este caso
                                                            //v[n] accede al elemento n-1 del vector, para ponerlo entero hay que 
                                                            //hacerlo con un for
    return 0;
}