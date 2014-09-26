
#include <stdlib.h>
#include <string.h> /* memcpy */

#include "CSPL_Stats_CDF.h"

/*   Compute the Cumulative distribution function from a tabular 
 *   set of data, the CDF is then defined as the percent of measurements
 *   less than X along the data.
 */

// from stdlib example docs
static int compare_doubles(const void *a, const void *b)
{
  const double *da = (const double *) a;
  const double *db = (const double *) b;

  return (*da > *db) - (*da < *db);
}


void CSPL_Stats_tCDF(double *datain, 
		     double *cdfout,
		     long n) {
  // compute the CDF from tabulted data, weights are 1

  /*  A random sample of size n from the distrubtion the CDF can be 
   *  estimated empirically from a tabulated data where CDF_n(x) is the
   *  number of observations less than or equal to x divided by n. 
   *  reperated values all have the same CDF value and that value
   *  is the upper (not averaged) probability.
   */

  long i, count;
  double *incopy; // do this so that the input array is not changed

  incopy = (double*)calloc(n, sizeof(double));
  memcpy(incopy, datain, sizeof(double)*n);
  
  // sort the data
  qsort(incopy, n, sizeof(double *), compare_doubles);
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









