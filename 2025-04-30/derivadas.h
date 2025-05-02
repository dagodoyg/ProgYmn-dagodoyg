#pragma once
#include <iostream>
#include <cmath>

using fptr=double(double);

double forward_diff(double x, double h,fptr f);
double central_diff(double x, double h,fptr f);
