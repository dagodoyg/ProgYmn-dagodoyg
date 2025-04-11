#include <iostream>
#include <cmath>
#include <cstdlib>

//Declaración de las funciones.

void pi_approx(int n); 
//double formula(int k);


//Llamado de la función.

int main(void){
    std::cout.precision(16); //En la terminal solo se ven los primeros 16 dígitos del resultado.
    std::cout.setf(std::ios::scientific); //Se piden los resultados en notación científica.
    int lim {1};
    std::cout << "Ingrese el limite de la suma\n"; //Pide que se especifique cuántos términos calcular.
    std::cin >> lim;
    pi_approx(lim); //Cálculo de la aproximación y desglose de resultados a través de la función pi_approx(n).
    return 0;
}


//Implementación.


void pi_approx(int n){
    //Declaración de las variables.
    double sum{0};
    double term{0};
    double abs_deviation{0};

    //Cálculo de la aproximación.
    for (int k=0; k<=n; k++)
    {   
        term = ( 1.0/std::pow(16,k) )*
    (   
        (4.0/(8*k+1)) -
        (2.0/(8*k+4)) -
        (1.0/(8*k+5)) - 
        (1.0/(8*k+6)) 
    );
        sum += term;
        //sum += formula(k)
    }

    //Cálculo de la diferencia relativa con respecto al expected value.
    abs_deviation = std::abs(1-(sum/M_PI));

    //Print de los resultados en la terminal
    std::cout << "Hasta el " << n << "-esimo termino de la serie, pi es aproximadamente " << sum << "\n"
                << "La diferencia relativa con respecto al valor esperado es " << abs_deviation << "\n";
}

/* formula por separado, es innecesario.
double formula(int k){
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
*/