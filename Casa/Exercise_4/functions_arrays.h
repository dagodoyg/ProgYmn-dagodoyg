#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>


double vector_norm(std::vector<double> v);
std::vector<double> poly_deriv(std::vector<double> v);
long int argmax(const std::vector<double> & u);
long int argmin(const std::vector<double> & u);
double p_norm(const std::vector<double> & u, long long int p);
double median(std::vector<double> u);
double percentil(std::vector<double> u, double i);
void fill_randomly(std::vector<double> & u);
void v_printer(const std::vector<double> & u);