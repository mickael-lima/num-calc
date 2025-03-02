#include <stdbool.h>
#include <math.h>
#include "../lib/num-calc.h"

/*
===== HELPER FUNCTIONS =====
*/
bool nc_opposite_sign(double a, double b) {return (a * b) < 0;}
double nc_interval_size(nc_interval *interval) {return interval->b - interval->a;}

/*
===== ROOT-FINDING ALGORITHM =====
*/
double nc_root_bisection(double f(double), nc_interval *r_interval, uint16 it) {
    double root = 0;

    double f_a = f(r_interval->a);
    double f_b = f(r_interval->b);

    // It is not necessary to search for a root if the root is already the bound of
    // the given interval.
    if(f_a == 0)
        root = r_interval->a;

    else if(f_b == 0)
        root = r_interval->b;

    // If f(a)*f(b) > 0 for the given interval, the root is not in [a, b], thus doesn't
    // make sense trying to compute it
    else if(f_b * f_a > 0)
        root = NAN;

    else {
        for(uint16 i = 0; i < it; i++) {
            double midpoint = (r_interval->a + r_interval->b) / 2;
            double f_midpoint = f(midpoint);

            if(nc_opposite_sign(f_a, f_midpoint))
                r_interval->b = midpoint;

            else if(nc_opposite_sign(f_b, f_midpoint))
                r_interval->a = midpoint;

            // If f(a)*f(b) > 0 after computing the midpoint, then the root is not in
            // the given interval.
            else {
                root = NAN;
                break;
            }

            root = midpoint;
        }
    }

    return root;
}
