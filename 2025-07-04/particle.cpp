#include "particle.h"
#include <fstream>
#include <iomanip>
#include <sstream>

void Particle::print(int iter, std::string FolderPath) {

    std::ostringstream ss;
    ss << FolderPath << "data-" << std::setw(5) << std::setfill('0') << iter << ".csv";
    std::string FileName = ss.str();

    std::ofstream output(FileName);
    if(output.is_open()==false) std::cerr << "Error abriendo el archivo\n";
    output << "x,y,z,rad,mass,vx,vy,vz,fx,fy,fz\n";
    output << R[0] << "," << R[1] << "," << R[2] << "," 
            << rad << "," << mass << ","  
            << V[0] << "," << V[1] << "," << V[2] << "," 
            << F[0] << "," << F[1] << "," << F[2];

    output.close();
}