/** @file
 *
 * Array implementations.
 */

#include <math.h>   

#include "CSPL_Stats_Normal.h"
#include "../Special/CSPL_Special.h"


/** return the normal distribution CDF given X, the mean, and stddev (sqrt(variance))
 * this is just the function, one can write another function to return an array
 *
 *
 * @param [in] x The position for the CDF.
 * @param [in] mean The mean of the input distribution.
 * @param [in] stddev The standard distribution of the input distribution.
 * @return The value of the cumulative probability distribution of the Normal distribution at position x.
 */
double CSPL_Stats_Normal_CDFfn(const double x,         // (input) position for the CDF
			       const double mean,      // (input) mean of the distribution
			       const double stddev) {  // (input) stddev of the distribution (sqrt(variance))
  return( 0.5*(1.0 + CSPL_Special_Erf( (x-mean)/(stddev*sqrt(2)) ) ) );
}


/** return the normal distribution quantile as used in testing
 * given F, the mean, and stddev (sqrt(variance))
 * this is just the function, one can write another function to return an array
 *
 *
 * @param [in] F The fraction of the quantile (e.g. 0.95).
 * @param [in] mean The mean of the input distribution.
 * @param [in] stddev The standard distribution of the input distribution.
 * @return The value of the cumulative probability distribution of the Normal distribution at position x.
 */
double CSPL_Stats_Normal_Quantilefn(const double F,         // (input) fraction for the quantile (e.g. 0.95)
				    const double mean,      // (input) mean of the distribution
				    const double stddev) {  // (input) stddev of the distribution (sqrt(variance))
  return( mean + stddev*sqrt(2) * CSPL_Special_Erf_inverse1(2.0*F-1.0)  );
}







