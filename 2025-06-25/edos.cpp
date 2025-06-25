#include "edos.h"

int main(void){


    return 0;
}

void derivada(double t, const state_t & y, state_t & dydt){
    dydt[0] = y[0]*(1-y[0]);
}


std::vector<double> integrate_euler (double t0, double tf, double dt, state_t & y0, state_t y){
    state_t dydt;
    dydt.resize(y.size());
    
    y = y0;

    for (double t = t0; t <= tf; t+=dt){
        derivada(t,y,dydt);
        y = y + dt*dydt;
    }    
}

