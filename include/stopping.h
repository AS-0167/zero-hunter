#ifndef STOPPING_CRITERIA_H
#define STOPPING_CRITERIA_H

#include "methods.h"

int check_stopping_criterion(double x_current, double x_previous, 
                           double f_current, double tolerance, 
                           StoppingCriterion criterion);

double estimate_bisection_iterations(double a, double b, double tolerance);
double estimate_fixed_point_iterations(double x0, double tolerance, double lambda);

#endif