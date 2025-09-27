#ifndef METHODS_H
#define METHODS_H

typedef double (*Function)(double);
typedef double (*Derivative)(double, double);

typedef struct {
    double root;
    int iterations;
    double *sequence;
    double final_error;
} RootResult;

typedef enum {
    STOPPING_FUNCTION_VALUE,
    STOPPING_ABSOLUTE_ERROR,
    STOPPING_RELATIVE_ERROR
} StoppingCriterion;

#endif