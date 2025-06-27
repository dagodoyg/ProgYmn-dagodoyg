
#pragma once

// ivp_solver.h
#include <iostream>
#include <valarray>
#include <functional>
#include <fstream>


// function template to work with "any" type
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t dsdt(s.size());

    std::ofstream euler("data_euler.txt");

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*dsdt; // Euler

        // write new state
        writer(s, t);
        euler << t << "\t" << s[0] << "\n";
      }

      euler.close();
}

template <class deriv_t, class system_t, class printer_t>
void integrate_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t k1(s.size());
    system_t k2(s.size());

    std::ofstream heun("data_heun.txt");

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, k1, t);
        fderiv(s + dt*k1, k2, t + dt);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*(k1 + k2)/2.0; // Heun's method

        // write new state
        writer(s, t);
        heun << t << "\t" << s[0] << "\n";
    }

    heun.close();
}

template <class deriv_t, class system_t, class printer_t>
void integrate_RK4(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    system_t k1(s.size());
    system_t k2(s.size());
    system_t k3(s.size());
    system_t k4(s.size());

    std::ofstream heun("data_RK4.txt");

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, k1, t);
        fderiv(s + dt*k1/2.0, k2, t + dt/2.0);
        fderiv(s + dt*k2/2.0, k3, t + dt/2.0);
        fderiv(s + dt*k3, k4, t + dt);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*(k1 + 2.0*k2 + 2*k3 + k4)/6.0; // RK$ method

        // write new state
        writer(s, t);
        heun << t << "\t" << s[0] << "\n";
    }

    heun.close();
}

