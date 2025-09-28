#ifndef PROBLEM4_H
#define PROBLEM4_H

#include "../../include/methods.h"

// Problem 4: Cryptography (Key Strength Estimation)
double f4_problem(double x);
double df4_problem(double x, double h);
void solve_problem4_newton(double x0, double tolerance, int max_iterations);
void solve_problem4_secant(double x0, double x1, double tolerance, int max_iterations);
void compare_problem4_stopping_criteria();

#endif