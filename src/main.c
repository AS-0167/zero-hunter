#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/methods.h"
#include "../include/bisection.h"
#include "../include/fixed_point.h"
#include "../include/newton.h"
#include "../include/regula_falsi.h"
#include "../include/secant.h"
#include "../include/stopping.h"
#include "../include/utils.h"

void print_menu();
void test_all_methods(Function f, Function g, Derivative df, double a, double b, 
                     double x0, double x1, double tolerance, 
                     StoppingCriterion criterion, int max_iterations);
void compare_stopping_criteria(Function f, Function g, Derivative df, double a, double b, 
                              double x0, double x1, double tolerance, 
                              int max_iterations);

int main() {
    int choice;
    double a, b, x0, x1, tolerance;
    int max_iterations;
    StoppingCriterion criterion;
    int function_choice;
    Function f, g;
    Derivative df;
    double h = 1e-6; // Step size for numerical derivatives
    
    printf("=== Generalized Root-Finding Toolkit ===\n\n");
    
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) break;
        
        // Select function
        printf("\nSelect function:\n");
        printf("1. f(x) = x^2 - 4 (Root: ±2)\n");
        printf("2. f(x) = x^3 - x - 2 (Root: ~1.521)\n");
        printf("3. f(x) = x^3 - 2x - 5 (Root: ~2.094)\n");
        printf("4. f(x) = cos(x) - x (Root: ~0.739)\n");
        printf("5. f(x) = x - e^(-x) (Root: ~0.567)\n");
        printf("Enter function choice (1-5): ");
        scanf("%d", &function_choice);
        
        switch (function_choice) {
            case 1: f = f1; g = g1; df = df1; break;
            case 2: f = f2; g = g2; df = df2; break;
            case 3: f = f3; g = g3; df = df3; break;
            case 4: f = f4; g = g4; df = df4; break;
            case 5: f = f5; g = g5; df = df5; break;
            default: printf("Invalid choice!\n"); continue;
        }
        
        printf("Enter tolerance: ");
        scanf("%lf", &tolerance);
        printf("Enter maximum iterations: ");
        scanf("%d", &max_iterations);
        
        switch (choice) {
            case 1: {
                printf("Enter interval [a, b]: ");
                scanf("%lf %lf", &a, &b);
                printf("Select stopping criterion:\n");
                printf("1. |f(x)| < tolerance\n");
                printf("2. |x_{k+1} - x_k| < tolerance\n");
                printf("3. |x_{k+1} - x_k|/|x_{k+1}| < tolerance\n");
                scanf("%d", &choice);
                criterion = choice - 1;
                
                RootResult result = bisection_method(f, a, b, tolerance, 
                                                   max_iterations, criterion);
                printf("\nBisection Method Results:\n");
                printf("Root: %.8f\n", result.root);
                printf("Iterations: %d\n", result.iterations);
                printf("Final Error: %.2e\n", result.final_error);
                printf("Estimated iterations: %.0f\n", 
                       estimate_bisection_iterations(a, b, tolerance));
                free(result.sequence);
                break;
            }
            
            case 2: {
                printf("Enter initial guess x0: ");
                scanf("%lf", &x0);
                printf("Select stopping criterion: ");
                scanf("%d", &choice);
                criterion = choice - 1;
                
                RootResult result = fixed_point_iteration(g, x0, tolerance, 
                                                        max_iterations, criterion);
                printf("\nFixed Point Iteration Results:\n");
                printf("Root: %.8f\n", result.root);
                printf("Iterations: %d\n", result.iterations);
                printf("Final Error: %.2e\n", result.final_error);
                free(result.sequence);
                break;
            }
            
            case 3: {
                printf("Enter initial guess x0: ");
                scanf("%lf", &x0);
                printf("Select stopping criterion: ");
                scanf("%d", &choice);
                criterion = choice - 1;
                
                RootResult result = newton_method(f, df, x0, tolerance, 
                                                max_iterations, criterion, h);
                printf("\nNewton's Method Results:\n");
                printf("Root: %.8f\n", result.root);
                printf("Iterations: %d\n", result.iterations);
                printf("Final Error: %.2e\n", result.final_error);
                free(result.sequence);
                break;
            }
            
            case 4: {
                printf("Enter interval [a, b]: ");
                scanf("%lf %lf", &a, &b);
                printf("Select stopping criterion: ");
                scanf("%d", &choice);
                criterion = choice - 1;
                
                RootResult result = regula_falsi_method(f, a, b, tolerance, 
                                                      max_iterations, criterion);
                printf("\nRegula Falsi Method Results:\n");
                printf("Root: %.8f\n", result.root);
                printf("Iterations: %d\n", result.iterations);
                printf("Final Error: %.2e\n", result.final_error);
                free(result.sequence);
                break;
            }
            
            case 5: {
                printf("Enter initial guesses x0, x1: ");
                scanf("%lf %lf", &x0, &x1);
                printf("Select stopping criterion: ");
                scanf("%d", &choice);
                criterion = choice - 1;
                
                RootResult result = secant_method(f, x0, x1, tolerance, 
                                                max_iterations, criterion);
                printf("\nSecant Method Results:\n");
                printf("Root: %.8f\n", result.root);
                printf("Iterations: %d\n", result.iterations);
                printf("Final Error: %.2e\n", result.final_error);
                free(result.sequence);
                break;
            }
            
            case 6: {
                printf("Enter interval [a, b]: ");
                scanf("%lf %lf", &a, &b);
                printf("Enter initial guess x0: ");
                scanf("%lf", &x0);
                x1 = x0 + 0.1; // For secant method
                test_all_methods(f, g, df, a, b, x0, x1, tolerance, 
                               STOPPING_ABSOLUTE_ERROR, max_iterations);
                break;
            }
            
            case 7: {
                printf("Enter interval [a, b]: ");
                scanf("%lf %lf", &a, &b);
                printf("Enter initial guess x0: ");
                scanf("%lf", &x0);
                x1 = x0 + 0.1;
                compare_stopping_criteria(f, g, df, a, b, x0, x1, tolerance, max_iterations);
                break;
            }
            
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }
    
    return 0;
}

void print_menu() {
    printf("=== Root-Finding Methods ===\n");
    printf("1. Bisection Method\n");
    printf("2. Fixed Point Iteration\n");
    printf("3. Newton's Method\n");
    printf("4. Regula Falsi Method\n");
    printf("5. Secant Method\n");
    printf("6. Test All Methods\n");
    printf("7. Compare Stopping Criteria\n");
    printf("0. Exit\n");
}

void test_all_methods(Function f, Function g, Derivative df, double a, double b, 
                     double x0, double x1, double tolerance, 
                     StoppingCriterion criterion, int max_iterations) {
    printf("\n=== Testing All Methods ===\n");
    
    double h = 1e-6;
    
    RootResult results[5];
    const char* method_names[] = {"Bisection", "Fixed Point", "Newton", "Regula Falsi", "Secant"};
    
    results[0] = bisection_method(f, a, b, tolerance, max_iterations, criterion);
    results[1] = fixed_point_iteration(g, x0, tolerance, max_iterations, criterion);
    results[2] = newton_method(f, df, x0, tolerance, max_iterations, criterion, h);
    results[3] = regula_falsi_method(f, a, b, tolerance, max_iterations, criterion);
    results[4] = secant_method(f, x0, x1, tolerance, max_iterations, criterion);
    
    printf("%-15s %-12s %-10s %-12s\n", "Method", "Root", "Iterations", "Final Error");
    printf("------------------------------------------------\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%-15s %-12.6f %-10d %-12.2e\n", 
               method_names[i], results[i].root, results[i].iterations, results[i].final_error);
        free(results[i].sequence);
    }
}

void compare_stopping_criteria(Function f, Function g, Derivative df, double a, double b, 
                              double x0, double x1, double tolerance, 
                              int max_iterations) {
    printf("\n=== Comparing Stopping Criteria ===\n");
    
    double h = 1e-6;
    
    const char* criteria_names[] = {"|f(x)|", "|x_k+1 - x_k|", "Relative Error"};
    
    printf("Bisection Method:\n");
    printf("%-15s %-12s %-10s\n", "Criterion", "Root", "Iterations");
    printf("------------------------------------\n");
    
    for (int i = 0; i < 3; i++) {
        RootResult result = bisection_method(f, a, b, tolerance, max_iterations, i);
        printf("%-15s %-12.6f %-10d\n", criteria_names[i], result.root, result.iterations);
        free(result.sequence);
    }
    
    printf("\nNewton's Method:\n");
    printf("%-15s %-12s %-10s\n", "Criterion", "Root", "Iterations");
    printf("------------------------------------\n");
    
    for (int i = 0; i < 3; i++) {
        RootResult result = newton_method(f, df, x0, tolerance, max_iterations, i, h);
        printf("%-15s %-12.6f %-10d\n", criteria_names[i], result.root, result.iterations);
        free(result.sequence);
    }
}