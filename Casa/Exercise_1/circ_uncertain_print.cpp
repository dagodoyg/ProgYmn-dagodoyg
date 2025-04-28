#include "functions.h"

int main(int argc, char **argv){
    double radius = std::stod(argv[1]);
    double uncert = std::stod(argv[2]);
    circ_uncertain(radius, uncert);
    return 0;
}

