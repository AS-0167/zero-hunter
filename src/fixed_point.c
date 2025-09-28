#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/fixed_point.h"
#include "../include/stopping.h"

RootResult fixed_point_iteration(Function g, double x0, double tolerance,
                               int max_iterations, StoppingCriterion criterion) {
    RootResult result;
    result.sequence = (double*)malloc(max_iterations * sizeof(double));
    result.iterations = 0;
    result.root = NAN;
    result.final_error = NAN;
    
    double x_current = x0;
    double x_previous = x0;
    int converged = 0;
    
    for (int i = 0; i < max_iterations; i++) {
        x_previous = x_current;
        x_current = g(x_previous);
        
        result.sequence[i] = x_current;
        result.iterations++;
        
        // Check for divergence
        if (isnan(x_current) || isinf(x_current)) {
            printf("Warning: Fixed point iteration diverged at iteration %d\n", i+1);
            break;
        }
        
        // Check stopping criterion
        if (check_stopping_criterion(x_current, x_previous, 
                                   x_current - x_previous, tolerance, criterion)) {
            result.root = x_current;
            result.final_error = fabs(x_current - x_previous);
            converged = 1;
            break;
        }
        
        // Check for oscillation or slow convergence
        if (i > 10 && fabs(x_current - x_previous) > fabs(result.sequence[i-1] - result.sequence[i-2])) {
            printf("Warning: Possible oscillation detected at iteration %d\n", i+1);
        }
    }
    
    if (!converged) {
        result.root = x_current;
        result.final_error = fabs(x_current - result.sequence[result.iterations-2]);
        printf("Warning: Fixed point iteration did not converge within %d iterations\n", max_iterations);
    }
    
    return result;
}