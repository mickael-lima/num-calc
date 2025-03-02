#ifndef NUM_CALC_H_
#define NUM_CALC_H_

typedef struct {
    double a;
    double b;
} nc_interval;

typedef unsigned int uint_16;

// Numerical methods for finding root
double nc_root_bisection(double f(double), nc_interval *r_interval, uint_16 it);

#endif // NUM_CALC_H_
