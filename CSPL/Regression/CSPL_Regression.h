
#ifndef CSPL_REGRESSION_H
#define CSPL_REGRESSION_H

#include "CSPL_MonteCarlo.h"

/* Theil-Sen regression */
double CSPL_Regression_TheilSen(double *x, double *y, long n, double *slope, double *intercept);

void CSPL_Regression_TheilSen_Jackknife(double *x, double *y, 
					long n, 
					CSPL_Jackknife *jn_slope, 
					CSPL_Jackknife *jn_int );

/* compute R-sq */
double CSPL_Regression_LinearRsq(double *x, double *y, long n, double slope, double intercept);

#endif /* CSPL_REGRESSION_H */


