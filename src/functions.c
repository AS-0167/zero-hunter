#include "../include/functions.h"
#include <math.h>

// f1: x^3 - x - 2
double f1(double x) { return x*x*x - x - 2.0; }
double df1(double x) { return 3.0*x*x - 1.0; }
double g1(double x) { // simple rearrangement: (x+2)^(1/3)
    if (x + 2.0 < 0.0) return -pow(fabs(x+2.0), 1.0/3.0);
    return pow(x + 2.0, 1.0/3.0);
}

// f2: cos(x) - x
double f2(double x) { return cos(x) - x; }
double df2(double x) { return -sin(x) - 1.0; }
double g2(double x) { return cos(x); }