#pragma once
#include <cmath>
#include <iostream>

bool is_prime(long long int n);
long long int sum_primes_lt(long long int n);
long long int great_prime_factor(long long int num);
long int sum_fibonacci_odd(long int num);

/*Nota:
unos de los casos de prueba del encabezado 1 y 2, dan lugar a valores que salen del rango de los long así que los dejé como long long
*/