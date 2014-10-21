
#include <stdio.h>
#include <stdlib.h>

#include "CSPL_Regression.h"
#include "../Stats/CSPL_Stats.h"

/** Compute the R-squared value of a linear fit
 * The return value is the R**2 as defined
 * as 1-SSres/SStot, where SSres is the residual sum of squares and SStot is the total 
 * sum of squares (proportional to the sample variance)
 *
 * @param[in] x The *sorted* x points to use in the regression.
 * @param[in] y The y values of the points to use in the regression.
 * @param[in] n The length of the x,y arrays;
 * @param[in] slope The calculated slope.
 * @param[in] intercept The calculated intercept.
 * @return R-squared value, 1-SSres/SStot.
 */
double CSPL_Regression_LinearRsq(double *x, double *y, long n, double slope, double intercept) {
  double ymean;
  long i;
  double SStot=0, SSres=0;
  
  // figure out the R**2 value
  ymean = CSPL_Stats_mean(y, n);
  for (i=0; i<n; i++) {
    SStot += ((y[i]-ymean)*(y[i]-ymean));
    // need sum of squared residuals
    SSres += ((y[i]-slope*x[i]+intercept)*(y[i]-slope*x[i]+intercept));
  }
  return(1-SSres/SStot);
}


