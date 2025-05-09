#pragma once
#include <cmath>
#include <iostream>
#include <functional>

using fptr = std::function<double(double)>;

double trapezoid(double a, double b, int N, fptr fun);