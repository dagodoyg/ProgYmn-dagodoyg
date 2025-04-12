//librerias

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>


//Declaración de las funciones.

void pi_approx(void); 
double formula(int k);
bool validation(double z);


//Llamado de la función.

int main(void){
    pi_approx(); //Cálculo de la aproximación y desglose de resultados a través de la función pi_approx().
    return 0;
}


//Implementación.

void pi_approx(void){
    //Declaración de las variables.
    double sum{0};
    double abs_deviation{0};
    double lim {0};
    char confirm;

    //Validación de la entrada.
    do {
        std::cout << "Ingrese un limite valido para la suma, debe ser un numero entero positivo o 0.\n"; //Pide que se especifique cuántos términos calcular.
        std::cin >> lim;
    } while (validation(lim)==false);


    //Revisión de los límites.
    double decimal_part=std::modf(lim,&lim);
    if(decimal_part!=0){ //Revisa si hay decimales y los retira.
        std::cout << "El limite ingresado no es un entero, se ha truncado a " << lim << "\n";
    }  else if ( std::isinf(std::abs(lim))==true ) { //Revisa si el numero ingresado causa un overflow.
        std::cout << "Overflow en la entrada, limite establecido por defecto a 0";
        lim=0;
    }  else if (lim>1e7) { //Aviso sobre el tiempo de cálculo.
        std::cout << "Usted solicito mas de "<<1e7<<" terminos, lo cual es innecesario. El tiempo de calculo podria prolongarse.\n";
    }

    //Cálculo de la aproximación.
    for (int k=0; k<=lim; k++)
    {   
        sum += formula(k);
    }

    //Cálculo de la diferencia relativa con respecto al expected value.
    abs_deviation = std::abs(1-(sum/M_PI));

    //Print de los resultados en la terminal
    std::cout << "Hasta el " << lim;
    std::cout.precision(16); //En la terminal solo se ven los primeros 16 dígitos del resultado.
    std::cout.setf(std::ios::scientific); //Se piden los resultados en notación científica.
    std::cout << "-esimo termino de la serie, pi es aproximadamente " << sum << "\n"
                << "La diferencia relativa con respecto al valor esperado es " << abs_deviation << "\n";
}

bool validation(double z){
    bool val=false;

    //Validación de la entrada.

    if (z<0){ //No numeros negativos.
        val=false;
    } else if ( std::cin.fail() ){ //Solo se aceptan números.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        val=false;
    } else {
        val=true;
    }
    return val;
}


double formula(int k){ //Formula de aproximación.
    double term {0};
    term = ( 1.0/std::pow(16,k) )*
    (   
        (4.0/(8*k+1)) -
        (2.0/(8*k+4)) -
        (1.0/(8*k+5)) - 
        (1.0/(8*k+6)) 
    );
    return term;
}
