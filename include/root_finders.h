#ifndef ROOT_FINDERS_H
#define ROOT_FINDERS_H

#include <stddef.h>
#include "stopping.h"

typedef double (*Func)(double);
typedef double (*DFunc)(double);

typedef struct {
    double root;
    int iterations;
    double *xs;      // dynamically allocated sequence of approximations
    int xs_len;      // length of xs
    double final_error;
} RootResult;

// Each algorithm returns a RootResult. Caller must free result->xs.

RootResult bisection(Func f, double a, double b, double eps, StopCriterion crit, int Nmax);
RootResult fixed_point(Func g, double x0, double eps, StopCriterion crit, int Nmax);
RootResult newton_method(Func f, DFunc df, double x0, double eps, StopCriterion crit, int Nmax);
RootResult regula_falsi(Func f, double a, double b, double eps, StopCriterion crit, int Nmax);
RootResult secant_method(Func f, double x0, double x1, double eps, StopCriterion crit, int Nmax);

// Iteration estimators
int estimate_bisection_iters(double a, double b, double eps);
int estimate_fixed_point_iters(double L, double x0, double eps); // L is contraction constant (0<L<1)
int estimate_experimental_iters_bisect_like(RootResult (*alg)(Func,double,double,double,StopCriterion,int), Func f, double a, double b, double eps, StopCriterion crit, int Nmax);

// utility to free result
void free_result(RootResult *r);

#endif // ROOT_FINDERS_H