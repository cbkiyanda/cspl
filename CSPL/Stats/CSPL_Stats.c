
#include <stdlib.h> /* qsort */
#include <string.h> /* memcpy */

#include "CSPL_Stats.h"
#include "../Sort/CSPL_Sort.h"



double CSPL_mean(double *inval, long n) {
  double sum=0;
  long i;

  for (i=0;i<n;i++)
    sum += inval[i];
  return (sum/(double)n);
}

double CSPL_median(double *inval, long n) {
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
    median = CSPL_mean(incopy, 2);
  } else {
    // median is the n/2th item
    median = incopy[((n+1)/2)-1];
  }
  free(incopy);  
  return(median);
}







