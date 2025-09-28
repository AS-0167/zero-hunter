#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/problem3.h"
#include "../../include/regula_falsi.h"
#include "../../include/stopping.h"
#include "../../include/bisection.h"

// f(D) = D - 70/(1 - e^(-0.02D)) - 5 = 0
double f3_problem(double D) {
    return D - 70.0 / (1.0 - exp(-0.02 * D)) - 5.0;
}

void solve_problem3_regula_falsi(double a, double b, double tolerance, int max_iterations) {
    printf("=== Problem 3: Regula Falsi (Networking) ===\n");
    printf("f(D) = D - 70/(1 - e^(-0.02D)) - 5 = 0, Interval: [%.1f, %.1f]\n", a, b);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    RootResult result = regula_falsi_method(f3_problem, a, b, tolerance, 
                                          max_iterations, STOPPING_ABSOLUTE_ERROR);
    
    printf("Root: %.8f\n", result.root);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f3_problem(result.root));
    
    free(result.sequence);
}

void solve_problem3_bisection(double a, double b, double tolerance, int max_iterations) {
    printf("=== Problem 3: Bisection Method (Networking) ===\n");
    printf("f(D) = D - 70/(1 - e^(-0.02D)) - 5 = 0, Interval: [%.1f, %.1f]\n", a, b);
    printf("Tolerance: %.0e, Max iterations: %d\n", tolerance, max_iterations);
    
    RootResult result = bisection_method(f3_problem, a, b, tolerance, 
                                       max_iterations, STOPPING_ABSOLUTE_ERROR);
    
    printf("Root: %.8f\n", result.root);
    printf("Iterations: %d\n", result.iterations);
    printf("Final Error: %.2e\n", result.final_error);
    printf("f(root) = %.2e\n", f3_problem(result.root));
    printf("Estimated iterations: %.0f\n", estimate_bisection_iterations(a, b, tolerance));
    
    free(result.sequence);
}

void compare_problem3_methods() {
    printf("=== Problem 3: Method Comparison (Networking) ===\n");
    
    double tolerance = 1e-5;
    int max_iterations = 50;
    
    RootResult regula_falsi = regula_falsi_method(f3_problem, 0, 100, tolerance, 
                                                max_iterations, STOPPING_ABSOLUTE_ERROR);
    RootResult bisection = bisection_method(f3_problem, 0, 100, tolerance, 
                                          max_iterations, STOPPING_ABSOLUTE_ERROR);
    
    printf("Regula Falsi: %d iterations\n", regula_falsi.iterations);
    printf("Bisection: %d iterations\n", bisection.iterations);
    printf("Bisection estimated: %.0f iterations\n", estimate_bisection_iterations(0, 100, tolerance));
    
    free(regula_falsi.sequence);
    free(bisection.sequence);
}