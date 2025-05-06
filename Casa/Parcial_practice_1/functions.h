#pragma once
#include <cmath>
#include <iostream>
#include <string>

bool is_prime(unsigned long long int n);
long long int sum_primes_lt(long long int n);
long long int great_prime_factor(long long int num);
long int sum_fibonacci_odd(long int num);
std::string four_digits(int num);
void bab_sqrt(double num , int iter);
int circ_uncertain(double radius , double uncert);
long long int smaller_prime(long long int num);
long long int great_collatz(long long int num);
long long int number_collatz(long long int num);
void sexy_primes_lt_p(long long int num);
long long int nth_twin_primes(long long int num);
/*Nota:
unos de los casos de prueba del encabezado 1 y 2, dan lugar a valores que salen del rango de los long así que los dejé como long long
*/