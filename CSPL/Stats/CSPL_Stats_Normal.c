
#include <math.h>   

#include "CSPL_Stats_Normal.h"
#include "../Special/CSPL_Special.h"


/*
 * function to return the normal distribution CDF
 * given X, the mean, and stddev (sqrt(variance))
 * this is just the function, one can write another function to return an array
 */
double CSPL_Stats_Normal_CDFfn(double x,         // (input) position for the CDF
				double mean,      // (input) mean of the distribution
				double stddev) {  // (input) stddev of the distribution (sqrt(variance))

  return( 0.5*(1.0 + CSPL_Special_Erf( (x-mean)/(stddev*sqrt(2)) ) ) );
}

/*
 * function to return the normal distribution quantile as used in testing
 * given F, the mean, and stddev (sqrt(variance))
 * this is just the function, one can write another function to return an array
 */
double CSPL_Stats_Normal_Quantilefn(double F,         // (input) fraction for the quantile (e.g. 0.95)
				    double mean,      // (input) mean of the distribution
				    double stddev) {  // (input) stddev of the distribution (sqrt(variance))

  return( mean + stddev*sqrt(2) * CSPL_Special_Erf_inverse1(2.0*F-1.0)  );


}







