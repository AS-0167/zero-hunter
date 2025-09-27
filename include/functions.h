#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "root_finders.h"

// Example functions and their derivatives used in demo problems

double f1(double x); // x^3 - x - 2
double df1(double x);

double g1(double x); // fixed-point transformation for f1: cube root(x+2)

double f2(double x); // cos(x) - x
double df2(double x);

double g2(double x); // fixed point: cos(x)

#endif // FUNCTIONS_H