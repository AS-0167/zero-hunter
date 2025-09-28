#ifndef PROBLEM2_H
#define PROBLEM2_H

#include "../../include/methods.h"

// Problem 2: Machine Learning (Threshold Calibration)
double f2_problem(double x);
double df2_problem(double x, double h);
double g2_problem(double x);

void solve_problem2_fixed_point(double x0, double tolerance, int max_iterations);
void solve_problem2_newton(double x0, double tolerance, int max_iterations);
void compare_problem2_methods();

#endif