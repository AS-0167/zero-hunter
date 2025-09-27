#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include "methods.h"

RootResult fixed_point_iteration(Function g, double x0, double tolerance,
                               int max_iterations, StoppingCriterion criterion);

#endif