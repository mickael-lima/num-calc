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

/*
===== LINEAR ALGEBRA=====
*/
typedef struct {
    double* elements;
    uint16 order;
} nc_matrix;

// Matrix
nc_matrix nc_create_matrix(uint16 order);
void nc_matrix_clmem(nc_matrix* matrix);
void nc_print_matrix(nc_matrix* matrix);
double nc_matrix_get_element(nc_matrix *matrix, uint16 i, uint16 j);

/*
===== DIFFERENTIAL CALCULUS =====
*/
double nc_dc_integral_simp(double f(double), nc_interval *integration_interval, uint16 it);

#endif // NUM_CALC_H_
