#ifndef UTILS_H
#define UTILS_H

#include "methods.h"

double** create_2d_array(int rows, int cols);
void free_2d_array(double** array, int rows);
double* create_1d_array(int size);
void print_array(double* array, int size);
double absolute_error(double x1, double x2);
double relative_error(double x1, double x2);

// Example functions for testing
double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);

// Fixed-point transformation functions
double g1(double x);
double g2(double x);
double g3(double x);
double g4(double x);
double g5(double x);

// Derivatives for Newton's method
double df1(double x, double h);
double df2(double x, double h);
double df3(double x, double h);
double df4(double x, double h);
double df5(double x, double h);

#endif