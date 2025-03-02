#include <stdbool.h>
#include <math.h>
#include "num-calc.h"

bool nc_opposite_sign(double a, double b) {
    return (a * b) < 0;
}

double nc_root_bisection(double f(double), nc_interval *r_interval, uint_16 it) {
    double root = 0;

    double f_a = f(r_interval->a);
    double f_b = f(r_interval->b);

    if(f_a == 0)
        root = r_interval->a;

    else if(f_b == 0)
        root = r_interval->b;

    else {
        for(uint_16 i = 0; i < it; i++) {
            double midpoint = (r_interval->a + r_interval->b) / 2;
            double f_midpoint = f(midpoint);

            if(nc_opposite_sign(f_a, f_midpoint))
                r_interval->b = midpoint;
            else if(nc_opposite_sign(f_b, f_midpoint))
                r_interval->a = midpoint;
            else {
                root = NAN;
                break;
            }

            root = midpoint;
        }
    }

    return root;
}
