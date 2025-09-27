#ifndef BISECTION_H
#define BISECTION_H

#include "methods.h"

RootResult bisection_method(Function f, double a, double b, double tolerance, 
                          int max_iterations, StoppingCriterion criterion);

#endif