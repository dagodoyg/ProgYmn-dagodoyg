#include <iostream>
#include "gen_sqr_str.h"

int main(int argc, char **argv){
    int length = std::stoi(argv[1]);
    char element = argv[2][0];
    std::cout << gen_square(length,element);
    return 0;
}