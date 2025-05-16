#include "Integrar_datos.h"
#include <fstream>
#include <vector>
#include <iomanip>

int main(void){

    std::ifstream file("data.txt");

    std::vector<double> x,y;
    double xi,yi;

    while (file >> xi >> yi) {
        x.push_back(xi);
        y.push_back(yi);
    }

    file.close();

    std::vector<double> v=trapezoid_acumulative(x,y);


    std::ofstream file2("v_data.txt");
    file2 << "t v\n";

    for (int jj{0}; jj<x.size(); jj++){
       file2 << x[jj] << " " << v[jj] << "\n";  
    }

    file2.close();


    return 0;
}