//librerias

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>

//Declaración de las funciones.

void pi_approx(void); 
double formula(int k);

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
    bool val=false;


    //Validación de la entrada.
    do {
        std::cout << "\033[32mIngrese un limite valido para la suma, debe ser un numero entero positivo o 0.\n\033[0m"; //Pide que se especifique cuántos términos calcular.
        std::cin >> lim;

        if (std::isinf(lim) || std::cin.fail()){ //Aviso de error
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "\033[31mError: el limite ingresado no es valido, limite establecido por defecto a 20. \033[0m\n";
            lim=20;
            val=true;
        } /*else if ( std::cin.fail()){ //Solo se aceptan números.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            val=false;
        } */ else if (lim<0){ //No numeros negativos.
            val=false;
            std::cerr << "\033[31mError: El numero ingresado debe ser POSITIVO.\033[0m\n";
        } else {
            val=true;
        }
        
    } while (val==false);


    //Revisión de los límites.
    double decimal_part=std::modf(lim,&lim); //Existen maneras de hacer esto más eficiente pero quiero mantenerlo como 
                                                //double para reducir el riesgo de under/over-flow
    if( decimal_part!=0 ){ //Revisa si hay decimales y los retira.;
        std::cout << "\033[34mEl limite ingresado no es un entero, se ha truncado a " << lim << "\n\033[0m";
    }  else if (lim>1e3) { //Aviso sobre el tiempo de cálculo.
        std::cout << "\033[34mUsted solicito mas de "<<1e3<<" terminos, lo cual es innecesario.\n"
                    << "El limite maximo se ha establecido en " << 1e3 <<"\n\033[0m";
        //No va a mostar una mejor aproximación más allá de lim=10 pues está puesto para
        //que solo se muestren hasta 16 dígitos en la terminal de todas formas.

        lim=1e3;
    }

    //Cálculo de la aproximación.
    for (int k=0; k<=lim; k++)
    {   
        sum += formula(k);
    }

    //Cálculo de la diferencia relativa con respecto al expected value.
    abs_deviation = std::abs(1-(sum/M_PI));

    //Print de los resultados en la terminal
    std::cout<< "\033[32mHasta el " << lim;

    std::ostringstream result_text;

    std::cout.precision(16); //En la terminal solo se ven los primeros 16 dígitos del resultado.
    std::cout.setf(std::ios::scientific); //Se piden los resultados en notación científica.

    std::cout << "-esimo termino de la serie, pi es aproximadamente " << sum << "\n"
                << "La diferencia relativa con respecto al valor esperado es " << abs_deviation << "\033[0m\n";

}


double formula(int k){ //Formula de aproximación.
    double term {0};

    //Precalculo para evitar repetirlo y gastar menos recursos.
    double pre_calc {8*k+1.0};
    double power=std::pow(16,k);

/*
    //Se puede optimizar acumulando sobre una variable pero pierde precisión,
        por eso decidí dejar el std::pow aunque sea significativamente menos eficiente.

    if (k>0){
        power*=16;    
    }
*/

    //Cálculo del k-ésimo término de la aproximación.
    term = ( 1.0/power )*
    (   
        (4.0/(pre_calc)) -
        (2.0/(pre_calc+3)) -
        (1.0/(pre_calc+4)) - 
        (1.0/(pre_calc+5)) 
    );
    return term;
}
