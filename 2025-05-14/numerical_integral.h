#pragma once
#include <cmath>
#include <iostream>
#include <functional>

using fptr = std::function<double(double)>;
using algptr = std::function<double(double, double, int, fptr)>;
double trapezoid(double a, double b, int N, fptr fun);
double simpson(double a, double b, int N, fptr fun);
double romberg(double a, double b, int m, fptr fun);
double richardson(double a, double b, int N, fptr f, algptr alg, int alpha);
double gauss_2(double a, double b, fptr fun);
double gauss_3(double a, double b, fptr fun);