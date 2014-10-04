
#include <math.h>   
#include <stdlib.h> /* qsort */
#include <string.h> /* memcpy */

#include "CSPL_Stats_CDF.h"
#include "../Sort/CSPL_Sort.h"
#include "../Array/CSPL_Array.h"
#include "../Special/CSPL_Special.h"

/*   Compute the Cumulative distribution function from a tabular 
 *   set of data, the CDF is then defined as the percent of measurements
 *   less than X along the data.
 */


void CSPL_Stats_tCDF_confidence_bands(double *cdf,
				      double *lowerband,
				      double *upperband,
				      double conf, 
				      long n ) {
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

void CSPL_Stats_tCDF(double *datain, 
		     double *cdfout,
		     long n) {
  // compute the CDF from tabulated data, weights are 1

  /*  A random sample of size n from the distribution the CDF can be 
   *  estimated empirically from a tabulated data where CDF_n(x) is the
   *  number of observations less than or equal to x divided by n. 
   *  repeated values all have the same CDF value and that value
   *  is the upper (not averaged) probability.
   */

  long i, count;
  double *incopy; // do this so that the input array is not changed

  incopy = (double*)calloc(n, sizeof(double));
  memcpy(incopy, datain, sizeof(double)*n);
  
  // sort the data
  qsort(incopy, n, sizeof(double *), CSPL_Sort_comparedoubles);
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






