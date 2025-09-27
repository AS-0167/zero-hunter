#include <math.h>
#include <stdio.h>
#include "../include/stopping.h"

int check_stopping_criterion(double x_current, double x_previous, 
                           double f_current, double tolerance, 
                           StoppingCriterion criterion) {
    switch (criterion) {
        case STOPPING_FUNCTION_VALUE:
            return fabs(f_current) < tolerance;
        
        case STOPPING_ABSOLUTE_ERROR:
            return fabs(x_current - x_previous) < tolerance;
        
        case STOPPING_RELATIVE_ERROR:
            if (fabs(x_current) < 1e-15) return 0; // Avoid division by zero
            return fabs(x_current - x_previous) / fabs(x_current) < tolerance;
        
        default:
            return 0;
    }
}

double estimate_bisection_iterations(double a, double b, double tolerance) {
    if (tolerance <= 0) return -1;
    return ceil(log2((b - a) / tolerance) - 1);
}

double estimate_fixed_point_iterations(double x0, double tolerance, double lambda) {
    if (lambda >= 1 || tolerance <= 0) return -1;
    // Theoretical bound: |x_n - x*| <= (lambda^n / (1-lambda)) * |x1 - x0|
    // We want lambda^n < tolerance * (1-lambda) / |x1 - x0|
    // For estimation, we assume |x1 - x0| ≈ 1
    return ceil(log(tolerance * (1 - lambda)) / log(lambda));
}