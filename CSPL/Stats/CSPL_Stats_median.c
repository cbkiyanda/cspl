 
#include <stdlib.h> /* qsort */
#include <string.h> /* memcpy */

#include "CSPL_Stats_median.h"
#include "CSPL_Stats.h"
#include "../Sort/CSPL_Sort.h"

/* Tibshirani, Ryan J. "Fast computation of the median by successive binning."  */
/* arXiv preprint arXiv:0806.3301 (2008). */

/** Compute the median of an array using the sort method. This is accurate
 * but extrmely slow compared to other methods
 * @param [in] inval The input array.
 * @param [in] n The length of the input array.
 * @return The value of the median.
 */ 
double CSPL_Stats_median_sort(double *inval, long n) {
  double *incopy; // do this so that the input array is not changed
  double median; 
  long index;
  double tmpvals[2]; // for the even case

  incopy = (double*)calloc(n, sizeof(double));
  memcpy(incopy, inval, sizeof(double)*n);
  
  // sort the data
  qsort(incopy, n, sizeof(double *), CSPL_Sort_comparedoubles);
  if ( 0 == n % 2) {
    index = (n/2)-1;
    tmpvals[0] = incopy[index];
    tmpvals[1] = incopy[index+1];
    median = CSPL_Stats_mean(tmpvals, 2);
  } else {
    // median is the n/2th item
    median = incopy[((n+1)/2)-1];
  }
  free(incopy);  
  return(median);
}

