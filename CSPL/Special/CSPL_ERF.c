
#include <math.h>

#include "CSPL_Special.h"
#include "../CSPL.h"

/*
 * Compute the error function with a maximal error of  1.5×10−7
 * Abramowitz, Milton, and Irene A. Stegun, eds. Handbook of mathematical functions: with formulas, graphs, 
 * and mathematical tables. No. 55. Courier Dover Publications, 1972.
 * only valid for x >= 0, erf(x) = -erf(-x)
 */
double CSPL_Special_Erf1(double x) { // (input) position to compute the error function
  double t;
  double tmp;
  double sign = CSPL_Sign(x);
  // constants from the paper
  double p = 0.3275911;
  double a1 = 0.254829592;
  double a2 = -0.284496736;
  double a3 = 1.421413741;
  double a4 = -1.453152027;
  double a5 = 1.061405429;
  t = 1.0/(1.0+p*(x*CSPL_Sign(x)));
  tmp = (a1*t + a2*t*t + a3*t*t*t + a4*t*t*t*t + a5*t*t*t*t*t);
  return ( CSPL_Sign(x) * (1-tmp/exp(x*x)) );
}

/* 
 * compute the approximation for the inverse Erf
 */
double CSPL_Special_Erf_inverse1(double x) { // (input) position to compute the inverse [-1, 1]
  // this is probably slow, lots of logs etc
  double sgn = CSPL_Sign(x);
  double a = 0.147;
  double v1, v2, v3;
  v1 = 2.0 / (CSPL_Pi*a);
  v2 = log(1.0-x*x)/2.0;
  v3 = log(1.0-x*x)/a;
  return( sgn*sqrt(sqrt((v1+v2)*(v1+v2) - v3) - (v1+v2))  );
}


