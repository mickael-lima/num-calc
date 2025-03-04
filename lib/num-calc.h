/**
 * @file num-calc.h
 *
 * General (and unique) header for `num-calc` library.
 */

#ifndef NUM_CALC_H_
#define NUM_CALC_H_

#include <stdbool.h>
#include <stdint.h>

/*! \brief Implementation of a math interval [a, b]
 *
 *  `nc-interval` is a short for `num-calc interval`. Creates a struct with two doubles `a` and `b`
 *  that represents the bound of the interval. Note that you can also use it as an open or half-open
 *  interval using the desired compare operator. When using this struct, keep in mind that `a < b` or
 *  else it could unlock some weird logic undefined behaviour in your code (ex: when integrating from
 *  `a` to `b`).
 */
typedef struct {
    double a;
    double b;
} nc_interval;

/*! \brief Check if `a` and `b` have opposite sign
 *
 * Not designed to be used directly by the user, but there's no harm in using it if you wish.
 *
 * \param a a double real number.
 * \param b a double real number.
 * \return `true` if `a` and `b` have both opposite sign, `false` otherwise.
 */
bool nc_opposite_sign(double a, double b);

/*! \brief Compute the interval length
 *
 * \param interval A `nc_interval` struct
 * \return A `double` real number
 * \see nc_interval
 */
double nc_interval_size(nc_interval *interval);

/*! \brief Compute the root in `[a, b]` interval using the bisection method.
 *
 *
 * \param f A function pointer to a function that returns a `double` and get a `double` as an argument
 * \param interval A `nc_interval` struct, the interval should have the root within.
 * \param it Number of iterations.
 * \return `(double)` An aproximation for the root
 * \see nc_interval, nc_interval_size
 */
double nc_root_bisection(double f(double), nc_interval *r_interval, uint16_t it);

/*! \brief Compute a definite integral using Simpson's method
 *
 * Computes the integral, from `a` to `b`, of the function `f`. Note that if `b < a`, the nc_interval_size
 * *should return a negative number* and thus will compute the integral with the correct sign.
 *
 * \param f A function pointer to a function that returns a `double` and get a `double` as an argument
 * \param interval A `nc_interval` struct
 * \param it Number of iterations.
 * \return `(double)` The integration result
 * \see nc_interval, nc_interval_size
 */
double nc_dc_integral_simp(double f(double), nc_interval *integration_interval, uint16_t it);

/*! \brief Compute a definite derivative
 *
 * Computes a definitive derivative of `f` at `x``
 * \param f A function pointer to a function that returns a `double` and get a `double` as an argument
 * \param x The point where the derivative should take place.
 * \param h The coefficient to use when taking the fake limit, smaller is better
 * \return `(double)` The slope of the tangent line at point
 * \see nc_dc_integral_simp
 */
double nc_dc_derivative(double f(double), double x, double h);

#endif // NUM_CALC_H_
