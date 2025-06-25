#pragma once
#include <functional>
#include <vector>
#include <valarray>

using state_t = std::valarray<double>;

void derivada(double t, const state_t & y, state_t & dy);
std::vector<double> integrate_euler (double t0, double tf, double dt, state_t & y0, state_t y);
