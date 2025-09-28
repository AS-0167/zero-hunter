#ifndef PROBLEM1_H
#define PROBLEM1_H

#include "../../include/methods.h"

// Problem 1: Computer Graphics (Ray Tracing)
double f1_problem(double t);
double df1_problem(double t, double h);

void solve_problem1_bisection(double a, double b, double tolerance, int max_iterations);
void solve_problem1_secant(double x0, double x1, double tolerance, int max_iterations);
void compare_problem1_methods();

#endif