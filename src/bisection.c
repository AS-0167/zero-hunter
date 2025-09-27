#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/bisection.h"
#include "../include/stopping.h"

RootResult bisection_method(Function f, double a, double b, double tolerance, 
                          int max_iterations, StoppingCriterion criterion) {
    RootResult result;
    result.sequence = (double*)malloc(max_iterations * sizeof(double));
    result.iterations = 0;
    
    if (f(a) * f(b) >= 0) {
        printf("Error: f(a) and f(b) must have opposite signs.\n");
        result.root = NAN;
        result.final_error = NAN;
        return result;
    }
    
    double c, fa, fb, fc;
    double previous_c = a;
    
    for (int i = 0; i < max_iterations; i++) {
        c = (a + b) / 2.0;
        fc = f(c);
        result.sequence[i] = c;
        result.iterations++;
        
        if (check_stopping_criterion(c, previous_c, fc, tolerance, criterion)) {
            result.root = c;
            result.final_error = fabs(c - previous_c);
            return result;
        }
        
        fa = f(a);
        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
        }
        previous_c = c;
    }
    
    result.root = c;
    result.final_error = fabs(c - previous_c);
    return result;
}