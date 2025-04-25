#include "gen_sqr_str.h"

std::string gen_square(int length,char element){

    std::ostringstream square;
    
    for (int jj=1 ; jj <= length ; jj++){
        for (int ii = 1 ; ii <= length ; ii++){
            if (jj==1 || jj==length || ii==1 || ii==length){
                square << element;
            } else {
                square << " ";
            }
        }
        square << "\n";
    }
    return square.str();
}