#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "newton.h"
#include "../include/stopping.h"

RootResult newton_method(Function f, Derivative df, double x0, double tolerance,
                       int max_iterations, StoppingCriterion criterion, double h) {
    RootResult result;
    result.sequence = (double*)malloc(max_iterations * sizeof(double));
    result.iterations = 0;
    
    double x_current = x0;
    double x_previous;
    double fx, dfx;
    
    result.sequence[0] = x0;
    result.iterations++;
    
    for (int i = 1; i < max_iterations; i++) {
        x_previous = x_current;
        fx = f(x_previous);
        dfx = df(x_previous, h);
        
        if (fabs(dfx) < 1e-15) {
            printf("Warning: Derivative is too small. Method may not converge.\n");
            result.root = x_current;
            result.final_error = NAN;
            return result;
        }
        
        x_current = x_previous - fx / dfx;
        result.sequence[i] = x_current;
        result.iterations++;
        
        if (check_stopping_criterion(x_current, x_previous, f(x_current), 
                                   tolerance, criterion)) {
            result.root = x_current;
            result.final_error = fabs(x_current - x_previous);
            return result;
        }
    }
    
    result.root = x_current;
    result.final_error = fabs(x_current - result.sequence[result.iterations-2]);
    return result;
}