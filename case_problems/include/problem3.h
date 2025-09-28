#ifndef PROBLEM3_H
#define PROBLEM3_H

#include "../../include/methods.h"

// Problem 3: Networking (Queue Delay Model)
double f3_problem(double D);
void solve_problem3_regula_falsi(double a, double b, double tolerance, int max_iterations);
void solve_problem3_bisection(double a, double b, double tolerance, int max_iterations);
void compare_problem3_methods();

#endif