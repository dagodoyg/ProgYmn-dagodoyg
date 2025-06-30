#include <iostream>
#include <valarray>
#include <functional>
#include <fstream>

typedef std::valarray<double> state_t; // alias for state type

template <class deriv_t, class system_t>
void solve_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt)
{
    // vector to store derivs
    system_t k1(s.size());
    system_t k2(s.size());

    std::ofstream heun("output-heun.txt");
    heun << "t\tx\tv\n"; 

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, k1, t);
        fderiv(s + dt*k1, k2, t + dt);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*(k1 + k2)/2.0; // Heun's method

        heun << t << "\t" << s[0] << "\t" << s[1] << "\n";
    }

    heun.close();
}

template <class deriv_t, class system_t>
void solve_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt)
{
    // vector to store derivs
    system_t dsdt(s.size());

    std::ofstream euler("output-euler.txt");
    euler << "t\tx\tv\n"; 

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*dsdt; // Euler

        euler << t << "\t" << s[0] << "\t" << s[1] << "\n";
      }

      euler.close();
}

int main(int argc, char** argv){
    double dt = std::stod(argv[1]);
    double t0 = std::stod(argv[2]);
    double tf = std::stod(argv[3]);
    double w = std::stod(argv[4]);
    state_t y(2);

    auto fun = [w](const state_t & y, state_t & dsdt, double t){
        dsdt[0] = y[1];  //Position derivative
        dsdt[1] = -1.0*w*w*y[0];  //Speed derivative
    };

    auto initial_con = [](state_t & y){
        y = {1,0};
    };

    initial_con(y);
    solve_euler(fun,y,t0,tf,dt);

    initial_con(y);
    solve_heun(fun,y,t0,tf,dt);

    return 0;
}