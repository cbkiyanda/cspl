 
#include <stdlib.h> /* qsort */
#include <string.h> /* memcpy */
#include <math.h>   /* log */

#include "CSPL_Stats_Median.h"
#include "CSPL_Stats.h"
#include "../Sort/CSPL_Sort.h"
#include "../Array/CSPL_Array.h"


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


/** Compute the median of an array using the quickselect method. 
 * if the input has an odd number of values this calls CSPL_Array_quickselect once
 * otherwise twice and averages. The median is the middle index
 * @param [in] inval The input array.
 * @param [in] n The length of the input array.
 * @return The value of the median.
 */ 
double CSPL_Stats_median_quickselect(double *inval, const long n) {
  double ans[2];
  unsigned long index;
  double outval;

  index = n/2; // We want integer division here
  if (0 == n % 2) { // even
    ans[0] = CSPL_Array_quickselect(index, inval, 0, n-1);
    index--;
    ans[1] = CSPL_Array_quickselect(index, inval, 0, n-1);
    outval = CSPL_Stats_mean(ans, 2);
  } else {
    outval = CSPL_Array_quickselect(index, inval, 0, n-1);
  }
  return(outval); 
}




