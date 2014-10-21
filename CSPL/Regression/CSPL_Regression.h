
#ifndef CSPL_REGRESSION_H
#define CSPL_REGRESSION_H

/* Theil-Sen regression */
double CSPL_Regression_TheilSen(double *x, double *y, long n, double *slope, double *intercept);
/* compute R-sq */
double CSPL_Regression_LinearRsq(double *x, double *y, long n, double slope, double intercept);

#endif /* CSPL_REGRESSION_H */


