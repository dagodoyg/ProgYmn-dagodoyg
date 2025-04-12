#include <stdio.h>

int main(void){
    FILE *fp=popen ("gnuplot -persist", "w");
    fprintf(fp, "plot sin(x) \n");
    fclose(fp);
    return 0;
}