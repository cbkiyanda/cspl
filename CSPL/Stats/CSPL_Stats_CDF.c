/** @file
 *
 * Statistics to compute and use cumulative probability distributions (CDF).
 */

#include <math.h>   

#include "CSPL_Stats_CDF.h"
#include "../Sort/CSPL_Sort.h"
#include "../Array/CSPL_Array.h"
#include "../Special/CSPL_Special.h"


/** Compute the Cumulative distribution function from a tabular 
 *   set of data, the CDF is then defined as the percent of measurements
 *   less than X along the data.
 *
 *
 * @param [in] cdf Input CDF to compute the confidence bands.
 * @param [out] lowerband The lower band values of the confidence.
 * @param [out] upperband The upper band values of the confidence.
 * @param [in] conf The confidence value desired for the bands (e.g. 95).
 * @param [in] n The length of the input and output arrays.
 */
void CSPL_Stats_tCDF_confidence_bands(const double *cdf,
				      double *lowerband,
				      double *upperband,
				      const double conf, 
				      const long n ) {
  /* given a CDF computed from an array compute and return the confidence  */
  /* bands of the CDF, this is done using the Dvoretzky-Kiefer-Wolfowitz (DKW)  */
  /* inequality     */
  /* the conf is the desired confidence, 95% is 0.05, 99% is 0.01   */
  double epsilon;
  long i;

  epsilon = sqrt( (1./(2.*(double)n)) * log((2./conf)) );
  for (i=0;i<n;i++) {
    lowerband[i] = cdf[i]-epsilon;
    upperband[i] = cdf[i]+epsilon;
  }
  CSPL_Array_clip(lowerband, 0, 1, n);    
  CSPL_Array_clip(upperband, 0, 1, n);    
}


/**  Compute the CDF from tabulated data, weights are 1
 * A random sample of size n from the distribution the CDF can be 
 *  estimated empirically from a tabulated data where CDF_n(x) is the
 *  number of observations less than or equal to x divided by n. 
 *  repeated values all have the same CDF value and that value
 *  is the upper (not averaged) probability.
 *
 *
 * @param [in] datain Input data to compute the CDF from.
 * @param [out] cdfout The values of the CDF.
 * @param [in] n The length of the input and output arrays.
 */
void CSPL_Stats_tCDF(const double *datain, 
		     double *cdfout,
		     const long n) {
  long i, count;
  double *incopy; // do this so that the input array is not changed

  CSPL_Array_copy(datain, incopy, 0, n, double);

  // sort the data
  CSPL_Sort_mergesort(incopy, n);
  // qsort(incopy, n, sizeof(double *), CSPL_Sort_comparedoubles);
  for (i=0;i<n;i++) {
    count = 0;
    while(incopy[count] <= incopy[i]) {
      count++;
      if ((n) <= count) break; // protect against over
    }
    cdfout[i] = (double)count/(double)n;
  }

  free(incopy);  
}






