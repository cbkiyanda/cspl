
#include <math.h>

#include "CSPL_Special.h"

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

