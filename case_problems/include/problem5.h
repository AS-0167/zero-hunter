#ifndef PROBLEM5_H
#define PROBLEM5_H

#include "../../include/methods.h"

// Problem 5: Robotics (Joint Angle Control)
double f5_problem(double theta);
double df5_problem(double theta, double h);
void solve_problem5_bisection(double a, double b, double tolerance, int max_iterations);
void solve_problem5_newton(double x0, double tolerance, int max_iterations);
void compare_problem5_methods();

#endif