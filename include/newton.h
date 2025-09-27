#ifndef NEWTON_H
#define NEWTON_H

#include "methods.h"

RootResult newton_method(Function f, Derivative df, double x0, double tolerance,
                       int max_iterations, StoppingCriterion criterion, double h);

#endif