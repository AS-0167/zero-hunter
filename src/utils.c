#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/utils.h"

double** create_2d_array(int rows, int cols) {
    double** array = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        array[i] = (double*)malloc(cols * sizeof(double));
    }
    return array;
}

void free_2d_array(double** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

double* create_1d_array(int size) {
    return (double*)malloc(size * sizeof(double));
}

void print_array(double* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%.6f", array[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

double absolute_error(double x1, double x2) {
    return fabs(x1 - x2);
}

double relative_error(double x1, double x2) {
    if (fabs(x2) < 1e-15) return fabs(x1 - x2); // Avoid division by zero
    return fabs(x1 - x2) / fabs(x2);
}

// Example functions
double f1(double x) { return x*x - 4; }                    // Root: ±2
double f2(double x) { return x*x*x - x - 2; }              // Root: ~1.521
double f3(double x) { return x*x*x - 2*x - 5; }            // Root: ~2.094
double f4(double x) { return cos(x) - x; }                 // Root: ~0.739
double f5(double x) { return x - exp(-x); }                // Root: ~0.567

// Derivatives
double df1(double x, double h) { return (f1(x+h) - f1(x-h)) / (2*h); }
double df2(double x, double h) { return (f2(x+h) - f2(x-h)) / (2*h); }
double df3(double x, double h) { return (f3(x+h) - f3(x-h)) / (2*h); }
double df4(double x, double h) { return (f4(x+h) - f4(x-h)) / (2*h); }
double df5(double x, double h) { return (f5(x+h) - f5(x-h)) / (2*h); }


// Fixed-point transformation functions
double g1(double x) { return x - f1(x); }
double g2(double x) { return x - f2(x); }
double g3(double x) { return x - f3(x); }
double g4(double x) { return x - f4(x); }
double g5(double x) { return x - f5(x); }