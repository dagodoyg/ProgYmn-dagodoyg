#include <vector>
#include <iostream>
#include <string>

double mean(const std::vector<double> & data);
void initialize(std::vector<double> & data);

int main(int argc , char **argv)
{
    // declare the vector
    std::vector<double> data; 

    // read the size from the command line
    const int N = std::stoi(argv[1]); 

    // resize the vector
    data.resize(N, 0);

    // initialize the data
    initialize(data);

    // compute the average
     std::cout.setf(std::ios::scientific);
    std::cout.precision(16);
    std::cout << mean(data) << "\n";

    return 0;
}

void initialize(std::vector<double> & data){
    for(int ii = 0; ii < data.size(); ii++) {
        data[ii] = ii;
    }
}

double mean(const std::vector<double> & data){
    double suma = 0.0;
    for(int ii = 0; ii < data.size(); ii++) {
        suma = suma + data[ii];
    }
    return suma/data.size();
}
//David Godoy
//Juan Diego Torres