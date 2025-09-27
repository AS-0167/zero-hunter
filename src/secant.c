#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "secant.h"
#include "../include/stopping.h"

RootResult secant_method(Function f, double x0, double x1, double tolerance,
                       int max_iterations, StoppingCriterion criterion) {
    RootResult result;
    result.sequence = (double*)malloc(max_iterations * sizeof(double));
    result.iterations = 0;
    
    double x_prev = x0;
    double x_curr = x1;
    double x_next;
    double f_prev, f_curr;
    
    result.sequence[0] = x0;
    result.sequence[1] = x1;
    result.iterations = 2;
    
    f_prev = f(x_prev);
    
    for (int i = 2; i < max_iterations; i++) {
        f_curr = f(x_curr);
        
        if (fabs(f_curr - f_prev) < 1e-15) {
            printf("Warning: Division by very small number. Method may not converge.\n");
            result.root = x_curr;
            result.final_error = NAN;
            return result;
        }
        
        x_next = x_curr - f_curr * (x_curr - x_prev) / (f_curr - f_prev);
        result.sequence[i] = x_next;
        result.iterations++;
        
        if (check_stopping_criterion(x_next, x_curr, f(x_next), tolerance, criterion)) {
            result.root = x_next;
            result.final_error = fabs(x_next - x_curr);
            return result;
        }
        
        x_prev = x_curr;
        x_curr = x_next;
        f_prev = f_curr;
    }
    
    result.root = x_curr;
    result.final_error = fabs(x_curr - result.sequence[result.iterations-2]);
    return result;
}