# `num-calc.h` - A Lightweight Numerical Methods Single-Header Library in `C`

This project aims to implements a collection of common numerical methods for solving math-related problems, prototyping algorithms or anything related to scientific computing. Optimized for speed and accuracy. 

## **Features** 
- **Modular**: Every piece of code can be reutilized, rewritten and reimplemented without affecting other parts of the library.
- **No dependencies**: It is enough to have a functional `C` compiler and `std-` library (`stdlib.h, stdbool.h`, etc) for using the library, making it easy to integrate into any `C/C++` project.
- **Easy to use**: Every method is straighfoward, just call a function and you're done.

## **Numerical Methods**

Below, a list of implemented methods (checked) and planned methods (unchecked).

### **Root-finding**

- [X] Bisection
- [ ] False Position
- [ ] Newton's method 
- [ ] Secant's method
- [ ] Brent's method

### **Linear Algebra**
- [ ] `2x2` matrix determinant through definition
- [ ] `NxN` matrix determinant through Laplace's Theorem.

### **Linear System Solver**
- [ ] Cramer's Rule
- [ ] Jacobi Iteration
- [ ] Inverse Matrix

### **Differential Calculus**
- [X] Simpson's method for Integral.
- [X] Numerical derivative.

## **Getting Started**

Documentation is generated using `Doxygen`, it parses the `num-calc.h` file directly. Run 

``` sh
doxygen docs/
```

to generate a `index.html` page with the documentation of every function in the header. A quick showcase of the library: computing the root of `f(x) = cos(x)e^(x)` in`[0.0001, 3.9999]` using the bisection method with `10000` iteration.

``` c
// Import everything you might need
#include <stdio.h>
#include <math.h>

// Import num-calc library in your project
#include "lib/num-calc.h"

// Define your math function
double f(double x) {
    return cos(x) * pow(M_E, x);
}

int main() {

    // Create a math interval
    nc_interval root_interval = {0.0001, 3.9999};

    // Use the bisection method
    double root = nc_root_bisection(f, &root_interval, 10000);

    // Print the result
    printf("%.20f\n", root);

    return 0;
}
```

It should return 

``` sh
1.57079632679489655800

real	0m0,004s
```

## License

This work is licensed under [`GPLv3`](https://www.tldrlegal.com/license/gnu-general-public-license-v3-gpl-3).
