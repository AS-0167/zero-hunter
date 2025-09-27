#ifndef SECANT_H
#define SECANT_H

#include "methods.h"

RootResult secant_method(Function f, double x0, double x1, double tolerance,
                       int max_iterations, StoppingCriterion criterion);

#endif