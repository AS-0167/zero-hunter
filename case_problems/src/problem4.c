#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/problem4.h"
#include "../../include/newton.h"
#include "../../include/secant.h"

// f(x) = log2(x) - 20 = 0
double f4_problem(double x) {
    return log2(x) - 20.0;
}

// f'(x) = 1/(x * ln(2))
double df4_problem(double x, double h) {
    return (f4_problem(x+h) - f4_problem(x-h)) / (2*h);
}

void solve_problem4_newton(double x0, double tolerance, int max_iterations) {
    printf("=== Problem 4: Newton's Method (Cryptography) ===\n");
    printf("f(x) = log2(x) - 20 = 0, Initial guess: %.0f\n", x0);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    double h = 1e-6;
    RootResult result = newton_method(f4_problem, df4_problem, x0, tolerance, 
                                    max_iterations, STOPPING_ABSOLUTE_ERROR, h);
    
    printf("Root: %.8f\n", result.root);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f4_problem(result.root));
    printf("2^20 = %.0f\n", pow(2, 20));
    
    free(result.sequence);
}

void solve_problem4_secant(double x0, double x1, double tolerance, int max_iterations) {
    printf("=== Problem 4: Secant Method (Cryptography) ===\n");
    printf("f(x) = log2(x) - 20 = 0, Initial guesses: %.0f, %.0f\n", x0, x1);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    RootResult result = secant_method(f4_problem, x0, x1, tolerance, 
                                    max_iterations, STOPPING_ABSOLUTE_ERROR);
    
    printf("Root: %.8f\n", result.root);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f4_problem(result.root));
    
    free(result.sequence);
}

void compare_problem4_stopping_criteria() {
    printf("=== Problem 4: Stopping Criteria Comparison (Cryptography) ===\n");
    
    double tolerance = 1e-5;
    int max_iterations = 50;
    double h = 1e-6;
    
    printf("Newton's Method:\n");
    RootResult newton_abs = newton_method(f4_problem, df4_problem, 1e5, tolerance, 
                                        max_iterations, STOPPING_ABSOLUTE_ERROR, h);
    RootResult newton_func = newton_method(f4_problem, df4_problem, 1e5, tolerance, 
                                         max_iterations, STOPPING_FUNCTION_VALUE, h);
    printf("  Absolute Error: %d iterations\n", newton_abs.iterations);
    printf("  Function Value: %d iterations\n", newton_func.iterations);
    
    printf("Secant Method:\n");
    RootResult secant_abs = secant_method(f4_problem, 1e5, 1e7, tolerance, 
                                        max_iterations, STOPPING_ABSOLUTE_ERROR);
    RootResult secant_func = secant_method(f4_problem, 1e5, 1e7, tolerance, 
                                         max_iterations, STOPPING_FUNCTION_VALUE);
    printf("  Absolute Error: %d iterations\n", secant_abs.iterations);
    printf("  Function Value: %d iterations\n", secant_func.iterations);
    
    free(newton_abs.sequence);
    free(newton_func.sequence);
    free(secant_abs.sequence);
    free(secant_func.sequence);
}