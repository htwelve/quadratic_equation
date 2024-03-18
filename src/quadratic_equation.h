#ifndef QUADRATIC_EQUATION
#define QUADRATIC_EQUATION

#include <math.h>
#include <stddef.h>

enum quad_flags {
  QUAD_TWO_SOLUTIONS = 2,
  QUAD_ONE_SOLUTION = 1,
  QUAD_NO_SOLUTIONS = 0,
  QUAD_ERROR = -1
};

int solve_equation(double a, double b, double c, double *x1, double *x2);

#endif