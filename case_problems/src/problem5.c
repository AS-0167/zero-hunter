#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/problem5.h"
#include "../../include/bisection.h"
#include "../../include/newton.h"
#include "../../include/stopping.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// f(θ) = sin(θ) - 0.3θ = 0
double f5_problem(double theta) {
    return sin(theta) - 0.3 * theta;
}

// f'(θ) = cos(θ) - 0.3
double df5_problem(double theta, double h) {
    return (f5_problem(theta+h) - f5_problem(theta-h)) / (2*h);
}

void solve_problem5_bisection(double a, double b, double tolerance, int max_iterations) {
    printf("=== Problem 5: Bisection Method (Robotics) ===\n");
    printf("f(θ) = sin(θ) - 0.3θ = 0, Interval: [%.1f, %.1f]\n", a, b);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    RootResult result = bisection_method(f5_problem, a, b, tolerance, 
                                       max_iterations, STOPPING_ABSOLUTE_ERROR);
    
    printf("Root: %.8f radians\n", result.root);
    printf("Root: %.8f degrees\n", result.root * 180.0 / M_PI);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f5_problem(result.root));
    printf("Estimated iterations: %.0f\n", estimate_bisection_iterations(a, b, tolerance));
    
    free(result.sequence);
}

void solve_problem5_newton(double x0, double tolerance, int max_iterations) {
    printf("=== Problem 5: Newton's Method (Robotics) ===\n");
    printf("f(θ) = sin(θ) - 0.3θ = 0, Initial guess: %.1f\n", x0);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    double h = 1e-6;
    RootResult result = newton_method(f5_problem, df5_problem, x0, tolerance, 
                                    max_iterations, STOPPING_ABSOLUTE_ERROR, h);
    
    printf("Root: %.8f radians\n", result.root);
    printf("Root: %.8f degrees\n", result.root * 180.0 / M_PI);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f5_problem(result.root));
    
    free(result.sequence);
}

void compare_problem5_methods() {
    printf("=== Problem 5: Method Comparison (Robotics) ===\n");
    
    double tolerance = 1e-5;
    int max_iterations = 50;
    double h = 1e-6;
    
    RootResult bisection = bisection_method(f5_problem, 0, 1, tolerance, 
                                          max_iterations, STOPPING_ABSOLUTE_ERROR);
    RootResult newton = newton_method(f5_problem, df5_problem, 0.5, tolerance, 
                                    max_iterations, STOPPING_ABSOLUTE_ERROR, h);
    
    printf("Bisection: %d iterations\n", bisection.iterations);
    printf("Newton: %d iterations\n", newton.iterations);
    printf("Bisection estimated: %.0f iterations\n", estimate_bisection_iterations(0, 1, tolerance));
    
    free(bisection.sequence);
    free(newton.sequence);
}