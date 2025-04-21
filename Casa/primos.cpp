#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
bool primo(int n){
 if(n<=1){ return false; }
 for(int ii=2;(ii*ii)<=n;ii++){
    if((n%ii==0)&&(ii!=n)){
        return false;
        } 
    }
    return true;
}

int main(void){
    int b=1000,contador=0;

    std::ofstream archivo("primos.txt"); //crea el archivo
    if (!archivo.is_open()) { //revisa que si esté abierto
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

        archivo << "Lim\tCantidad\n"; //encabezados

for(int s=2; s<=b; s++){
    contador = 0;
    for (int i=1; i<=s; i++){
        contador+=primo(i); //cuenta la cantidad de primos menores a s
    }

        archivo << s << "\t" << contador << "\n"; //imprime en el txt

}

archivo.close(); //cierra el archivo

//std::cout << "Entre 1"<< " y " << b << " hay " << contador << " numeros primos.";

    FILE *fp=popen ("gnuplot -persist", "w");
    fprintf(fp, "cd 'C:\\Users\\david\\OneDrive\\Universidad\\Programación y mn\\Casa'\n");
    fprintf(fp, "set key autotitle columnhead\n");
    fprintf(fp, "plot 'primos.txt' title 'numeros primos' linetype 7 linecolor 7\n");
    fclose(fp);
    return 0;
}
