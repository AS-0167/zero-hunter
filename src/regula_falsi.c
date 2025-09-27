#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "regula_falsi.h"
#include "../include/stopping.h"

RootResult regula_falsi_method(Function f, double a, double b, double tolerance,
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
    fa = f(a);
    fb = f(b);
    
    for (int i = 0; i < max_iterations; i++) {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);
        result.sequence[i] = c;
        result.iterations++;
        
        if (check_stopping_criterion(c, previous_c, fc, tolerance, criterion)) {
            result.root = c;
            result.final_error = fabs(c - previous_c);
            return result;
        }
        
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        previous_c = c;
    }
    
    result.root = c;
    result.final_error = fabs(c - previous_c);
    return result;
}