#ifndef REGULA_FALSI_H
#define REGULA_FALSI_H

#include "methods.h"

RootResult regula_falsi_method(Function f, double a, double b, double tolerance,
                             int max_iterations, StoppingCriterion criterion);

#endif