
#include <stdio.h>
#include <stdlib.h>

#include "CSPL_Regression.h"
#include "../Stats/CSPL_Stats.h"
#include "../MonteCarlo/CSPL_MonteCarlo.h"

/** compute the robust Theil-Sen linear regression coefficients.
 * This also provides Jackknife confidence bands around the 
 * regression parameters
 */
void CSPL_Regression_TheilSen_Jackknife(double *x, double *y, 
					long n,
					CSPL_Jackknife *jn_slope, 
					CSPL_Jackknife *jn_int ) {
  long ind_out;
  double *xx;
  double *yy;
  long i;
  double slope_tmp, intercept_tmp;

  CSPL_Regression_TheilSen(x, y, n, &slope_tmp, &intercept_tmp);
  jn_slope->centerval = slope_tmp;
  jn_int->centerval   = intercept_tmp;
  jn_slope->nreps     = 10;
  jn_int->nreps       = 10;


  xx = (double *)calloc(n-1, sizeof(double));
  yy = (double *)calloc(n-1, sizeof(double));
  jn_slope->data = (double *)calloc(n, sizeof(double));
  jn_int->data = (double *)calloc(n, sizeof(double));

  for (ind_out=0; ind_out<n; ind_out++) {
    // populate tmp arrays with the data except the one left out
    // TODO some thinking could make this two CSPL_Array_copy()
    for (i=0; i<n; i++) {
      if (i == ind_out) {
	continue;
      } else if (i > ind_out) {
	xx[i-1] = x[i];
	yy[i-1] = y[i];
      } else {
	xx[i] = x[i];
	yy[i] = y[i];
      }
    }
    // call CSPL_Regression_TheilSen() on the new data
    CSPL_Regression_TheilSen(xx, yy, n-1, &slope_tmp, 
			     &intercept_tmp);
    jn_slope->data[ind_out] = slope_tmp;
    //jn_slope->nreps++;
    jn_int->data[ind_out] = intercept_tmp;
    //jn_int->nreps++;
  }

  
  free(xx);
  free(yy);
  free(jn_slope->data);
  free(jn_int->data);
}



/** compute the robust Theil-Sen linear regression coefficients.
 * Taken from Theil, H. (1950), A rank-invariant method of linear and polynomial regression analysis. 
 * I, II, III, Nederl. Akad. Wetensch., Proc. 53: 386–392, 521–525, 1397–1412, MR 0036489.
 * and Sen, Pranab Kumar (1968), Estimates of the regression coefficient based on Kendall's tau, 
 * Journal of the American Statistical Association 63: 1379–1389, JSTOR 2285891, MR 0258201.
 * 
 * This is done but finding all the slopes between each two-points, then the median
 * of the slopes is the returned slope. Then the intercept is the median of all the 
 * intercepts using the derived slope at each point. The return value is the R**2 as defined
 * as 1-SSres/SStot, where SSres is the residual sum of squares and SStot is the total 
 * sum of squares (proportional to the sample variance)
 *
 * TODO this should be updated to give a confidence interval via bootstrap!
 *
 * @param[in] x The *sorted* x points to use in the regression.
 * @param[in] y The y values of the points to use in the regression.
 * @param[in] n The length of the x,y arrays;
 * @param[out] slope The calculated slope.
 * @param[out] intercept The calculated intercept.
 * @return R-squared value, 1-SSres/SStot.
 */
double CSPL_Regression_TheilSen(double *x, double *y, long n, double *slope, double *intercept) {
  double *slopes;
  double *intercepts;
  double dx;
  unsigned long i, j, k;
  unsigned long combs;
  double rsq;
  
  combs = CSPL_Stats_combination(n, 2); // number of point combinations of n data points
      
  if (combs == 0) {
    fprintf(stderr, "CSPL_Regression_TheilSen: Data has one or zero length, no calcualtion posssible\n");
    return(-1); // do we want to do more?
  }
   
  slopes     = (double *)calloc(combs, sizeof(double));
  intercepts = (double *)calloc(combs, sizeof(double));

  k=0;
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) { // this is the over ahead
      dx = (x[j]-x[i]);
      slopes[k] = ((y[j]-y[i])/dx);
      k++;
    }
  }

  *slope = CSPL_Stats_median_quickselect(slopes, combs); 

  // now loop over all the points and get the intercepts
  for (i=0;i<n;i++) {
    intercepts[i] = y[i] - *slope*x[i];
  }
  *intercept = CSPL_Stats_median_quickselect(intercepts, n); 

  // figure out the R**2 value
  rsq = CSPL_Regression_LinearRsq(x, y, n, *slope, *intercept);

  free(slopes);
  free(intercepts);
  return(rsq);
}


