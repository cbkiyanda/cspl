#include <stdio.h>
#include <stdlib.h>

#include "../../CSPL/Regression/CSPL_Regression.h"
#include "../../CSPL/MonteCarlo/CSPL_MonteCarlo.h"


int main(void) {
  double x[10] = {1,2,3,4,5,6,7,8,9, 10};
  double y[10] = {0.86074211,  2.243673  ,  2.32922599,  3.5269751 ,  5.19649183,
		  4.55875795,  8.6822283 ,  7.86981641,  9.0570581 ,  7.766994};
  long i;
  double slope, intercept;
  double rsq;
  CSPL_Jackknife *jn_slope;
  CSPL_Jackknife *jn_int;

  jn_slope = (CSPL_Jackknife *)calloc(1, sizeof(CSPL_Jackknife));
  jn_int = (CSPL_Jackknife *)calloc(1, sizeof(CSPL_Jackknife));

  //void CSPL_Regression_TheilSen(double *x, double *y, long n, double *slope, double *intercept)
  rsq = CSPL_Regression_TheilSen(x, y, 10, &slope, &intercept);
  
  printf("%10s\t%10s\n", "x", "y");
  for (i=0; i<10; i++) {
    printf("%10.2lf\t%10.2lf\n", x[i], y[i]);
  }
  printf("\n");
  printf("Slope: %lf, Intercept=%lf, R**2=%lf\n", slope, intercept, rsq);

  CSPL_Regression_TheilSen_Jackknife(x, y, 10, jn_slope, jn_int );
  printf("Done with Jackknife, time to compute the values\n");
  CSPL_Compute_Jackknife(jn_slope);
  CSPL_Compute_Jackknife(jn_int);

  printf("Slope:%lf  mean:%lf  var:%lf  bias:%lf\n", 
	 slope, jn_slope->mean, jn_slope->var, jn_slope->bias);
  printf("Intercept:%lf  mean:%lf  var:%lf  bias:%lf\n", 
	 intercept, jn_int->mean, jn_int->var, jn_int->bias);


  free(jn_slope);
  free(jn_int);

  return(0);
}

