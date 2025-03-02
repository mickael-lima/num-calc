#ifndef NUM_CALC_H_
#define NUM_CALC_H_

#include <stdbool.h>

typedef struct {
    double a;
    double b;
} nc_interval;

typedef unsigned int uint16;

/*
===== HELPER FUNCTIONS =====
*/
bool nc_opposite_sign(double a, double b);
double nc_interval_size(nc_interval *interval);

/*
===== ROOT-FINDING ALGORITHM =====
*/
double nc_root_bisection(double f(double), nc_interval *r_interval, uint16 it);

// Numerical methods for finding root
double nc_root_bisection(double f(double), nc_interval *r_interval, uint_16 it);

#endif // NUM_CALC_H_
