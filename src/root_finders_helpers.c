#include "../include/root_finders.h"
#include <math.h>

int estimate_bisection_iters(double a, double b, double eps) {
    if (eps <= 0) return -1;
    double ratio = (b - a) / eps;
    if (ratio <= 0) return 0;
    return (int)ceil(log2(ratio));
}

int estimate_fixed_point_iters(double L, double x0, double eps) {
    // theoretical bound: |x_n - x*| <= (L^n)/(1-L) |x1 - x0|
    // solve for n approximately using geometric series upper bound; here we use a simple conservative estimate
    if (L <= 0 || L >= 1) return -1; // can't estimate
    double numerator = log(eps*(1.0 - L));
    double denom = log(L);
    int n = (int)ceil(numerator/denom);
    return n>0? n: 0;
}

int estimate_experimental_iters_bisect_like(RootResult (*alg)(Func,double,double,double,StopCriterion,int), Func f, double a, double b, double eps, StopCriterion crit, int Nmax) {
    // Simple wrapper to run algorithm and return iterations used
    RootResult r = alg(f, a, b, eps, crit, Nmax);
    int it = r.iterations;
    free(r.xs);
    return it;
}