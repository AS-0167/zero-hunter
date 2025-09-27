#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fixed_point.h"
#include "../include/stopping.h"

RootResult fixed_point_iteration(Function g, double x0, double tolerance,
                               int max_iterations, StoppingCriterion criterion) {
    RootResult result;
    result.sequence = (double*)malloc(max_iterations * sizeof(double));
    result.iterations = 0;
    
    double x_current = x0;
    double x_previous;
    result.sequence[0] = x0;
    result.iterations++;
    
    for (int i = 1; i < max_iterations; i++) {
        x_previous = x_current;
        x_current = g(x_previous);
        result.sequence[i] = x_current;
        result.iterations++;
        
        if (check_stopping_criterion(x_current, x_previous, 
                                   x_current - x_previous, tolerance, criterion)) {
            result.root = x_current;
            result.final_error = fabs(x_current - x_previous);
            return result;
        }
    }
    
    result.root = x_current;
    result.final_error = fabs(x_current - result.sequence[result.iterations-2]);
    return result;
}