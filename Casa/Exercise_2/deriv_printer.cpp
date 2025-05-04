#include "derivadas.h"
#include <fstream>

double f(double x);

int main(void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    double x {1.234};
    //double h {0.01};

    std::ofstream file("derivatives.txt");

    file<<"x h forward central exact ferr cerr rferr rcerr\n";

        for (double h = 0.1; h >= 1e-10; h/=10)
        {
            double forward = forward_diff(x,h,f);
            double central = central_diff(x,h,f);
            double exact = exp(x);
            double richard1  = richardson(x,h,f,forward_diff,1);
            double richard2  = richardson(x,h,f,central_diff,2);

            file << x << " "
                << h << " "
                << forward << " "
                << central << " "
                << exact << " "
                << std::abs(1-forward/exact) << " " 
                << std::abs(1-central/exact) << " "
                << std::abs(1-richard1/exact) << " "
                << std::abs(1-richard2/exact) << "\n";
        }

    file.close();
    return 0;
    
}

double f(double x){
    return exp(x);
}



/*
Codigo de gnuplot útil

set logscale x 
set key autotitle columnhead
splot "data.txt" u 1:2:3 title "" w p pt 7 \\3d
plot "data.txt" u 1:2 title "" w l lt 7 \\2d lineas
plot "data.txt" u 1:2 , "data.txt" u 3:4 \\2d varios data sets
        // 1:2:3 = x_coord:y_coord:z_coord
set autoscale
cd "fold1/fold2/.../foldn" \\ir a la carpeta, importantes las comillas
help function
set xlabel "x"

*/