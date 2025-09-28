#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/problem1.h"
#include "../../include/bisection.h"
#include "../../include/secant.h"
#include "../../include/stopping.h"

// f(t) = t^2 - 5t + 6 = 0
double f1_problem(double t) {
    return t*t - 5*t + 6;
}

// f'(t) = 2t - 5
double df1_problem(double t, double h) {
    return (f1_problem(t+h) - f1_problem(t-h)) / (2*h);
}

void solve_problem1_bisection(double a, double b, double tolerance, int max_iterations) {
    printf("=== Problem 1: Bisection Method (Ray Tracing) ===\n");
    printf("f(t) = t^2 - 5t + 6 = 0, Interval: [%.1f, %.1f]\n", a, b);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    RootResult result = bisection_method(f1_problem, a, b, tolerance, 
                                       max_iterations, STOPPING_ABSOLUTE_ERROR);
    
    printf("Root: %.8f\n", result.root);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f1_problem(result.root));
    
    free(result.sequence);
}

void solve_problem1_secant(double x0, double x1, double tolerance, int max_iterations) {
    printf("=== Problem 1: Secant Method (Ray Tracing) ===\n");
    printf("f(t) = t^2 - 5t + 6 = 0, Initial guesses: %.1f, %.1f\n", x0, x1);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    RootResult result = secant_method(f1_problem, x0, x1, tolerance, 
                                    max_iterations, STOPPING_ABSOLUTE_ERROR);
    
    printf("Root: %.8f\n", result.root);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f1_problem(result.root));
    
    free(result.sequence);
}

void compare_problem1_methods() {
    printf("=== Problem 1: Method Comparison (Ray Tracing) ===\n");
    
    double tolerance = 1e-5;
    int max_iterations = 50;
    
    // Test both stopping criteria
    RootResult bisection_abs = bisection_method(f1_problem, 0, 5, tolerance, 
                                              max_iterations, STOPPING_ABSOLUTE_ERROR);
    RootResult bisection_func = bisection_method(f1_problem, 0, 5, tolerance, 
                                               max_iterations, STOPPING_FUNCTION_VALUE);
    
    RootResult secant_abs = secant_method(f1_problem, 0, 5, tolerance, 
                                        max_iterations, STOPPING_ABSOLUTE_ERROR);
    RootResult secant_func = secant_method(f1_problem, 0, 5, tolerance, 
                                         max_iterations, STOPPING_FUNCTION_VALUE);
    
    printf("Bisection Method:\n");
    printf("  Absolute Error Criterion: %d iterations\n", bisection_abs.iterations);
    printf("  Function Value Criterion: %d iterations\n", bisection_func.iterations);
    
    printf("Secant Method:\n");
    printf("  Absolute Error Criterion: %d iterations\n", secant_abs.iterations);
    printf("  Function Value Criterion: %d iterations\n", secant_func.iterations);
    
    free(bisection_abs.sequence);
    free(bisection_func.sequence);
    free(secant_abs.sequence);
    free(secant_func.sequence);
}