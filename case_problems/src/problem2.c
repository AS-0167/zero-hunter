#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/problem2.h"
#include "../../include/fixed_point.h"
#include "../../include/newton.h"

// f(x) = 1/(1 + e^(-x)) - 0.8 = 0
double f2_problem(double x) {
    return 1.0 / (1.0 + exp(-x)) - 0.8;
}

// f'(x) = e^(-x) / (1 + e^(-x))^2
double df2_problem(double x, double h) {
    return (f2_problem(x+h) - f2_problem(x-h)) / (2*h);
}

// g(x) = ln(0.8/(1-0.8)) = ln(4)
double g2_problem(double x) {
    return log(4.0); // Constant function for this specific problem
}

void solve_problem2_fixed_point(double x0, double tolerance, int max_iterations) {
    printf("=== Problem 2: Fixed Point Iteration (ML Threshold) ===\n");
    printf("f(x) = 1/(1 + e^(-x)) - 0.8 = 0, Initial guess: %.1f\n", x0);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    RootResult result = fixed_point_iteration(g2_problem, x0, tolerance, 
                                            max_iterations, STOPPING_FUNCTION_VALUE);
    
    printf("Root: %.8f\n", result.root);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f2_problem(result.root));
    printf("σ(root) = %.8f\n", 1.0 / (1.0 + exp(-result.root)));
    
    free(result.sequence);
}

void solve_problem2_newton(double x0, double tolerance, int max_iterations) {
    printf("=== Problem 2: Newton's Method (ML Threshold) ===\n");
    printf("f(x) = 1/(1 + e^(-x)) - 0.8 = 0, Initial guess: %.1f\n", x0);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    double h = 1e-6;
    RootResult result = newton_method(f2_problem, df2_problem, x0, tolerance, 
                                    max_iterations, STOPPING_FUNCTION_VALUE, h);
    
    printf("Root: %.8f\n", result.root);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f2_problem(result.root));
    printf("σ(root) = %.8f\n", 1.0 / (1.0 + exp(-result.root)));
    
    free(result.sequence);
}

void compare_problem2_methods() {
    printf("=== Problem 2: Method Comparison (ML Threshold) ===\n");
    
    double tolerance = 1e-5;
    int max_iterations = 50;
    double h = 1e-6;
    
    RootResult fixed_point = fixed_point_iteration(g2_problem, 1.0, tolerance, 
                                                 max_iterations, STOPPING_FUNCTION_VALUE);
    RootResult newton = newton_method(f2_problem, df2_problem, 1.0, tolerance, 
                                    max_iterations, STOPPING_FUNCTION_VALUE, h);
    
    printf("Fixed Point Iteration: %d iterations\n", fixed_point.iterations);
    printf("Newton's Method: %d iterations\n", newton.iterations);
    
    free(fixed_point.sequence);
    free(newton.sequence);
}