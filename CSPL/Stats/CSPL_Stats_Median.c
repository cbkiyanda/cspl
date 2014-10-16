 
#include <stdio.h>
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


double CSPL_Stats_median_bin(double *inval, const long n) {
  double mean, std, median=0;
  //  const unsigned long NBINS=1001; // the 1 is edges
  const unsigned long NBINS=11; // the 1 is edges
  double *bins; // the 1000 is a hardcoded optimization from the paper
  long *binscnt; 
  unsigned long underflow=0;
  unsigned long overflow=0;
  double diff;
  unsigned long i;
  unsigned long ind;
  unsigned long sum;
  long median_bin=-1; // impossible value
  long n_med;
  double *pts_in_bin;
  long cnt;
  long samenums;
  double tmpval;

  // if n is even build this later
  if (0 == n%2) {
    fprintf(stderr, "** CSPL_Stats_median_bin, only odd length arrays implemented **\n");
    return(-1);
  }

  n_med = (n+1)/2; // this is the number of points below that makes median

  bins   = (double *)calloc(NBINS, sizeof(double));
  binscnt = ( long *)calloc(NBINS-1, sizeof( long));

  mean = CSPL_Stats_mean(inval, n);
  std  = CSPL_Stats_std(inval, n);
  CSPL_Array_linspace(bins, mean-std, mean+std, NBINS);
  diff = bins[1]-bins[0];

  
  // loop over the array bin up the data in the linspace range
  for (i=0;i<n;i++) {
    if (inval[i] < bins[0]) {
      underflow++;
    } else if (inval[i] > bins[NBINS-1]) {
      overflow++;
    } else {
      ind = (unsigned long)((inval[i]-bins[0])/diff);
      binscnt[ind]++;
    }
  }
  // find the bins with the median in it
  sum = underflow; // sum get saved here and used later on
  for (i=0; i<NBINS-1; i++) {
    sum += binscnt[i];
    if (sum >= n_med) { // it is in this bin
      median_bin = i;
      break;
    }
  }
  // we know how many points are in this bin, find them and store them
  pts_in_bin = (double *)calloc(binscnt[median_bin], sizeof(double));
  // loop over all the input until we find all N points
  cnt=0;
  for (i=0;i<n;i++) {
    ind = (unsigned long)((inval[i]-bins[0])/diff);
    if (ind == (median_bin) ) { // this is one of them
      pts_in_bin[cnt] = inval[i];
      cnt++;
      //      printf("Found a point in the bin: %lf cnt=%ld, ind=%ld, median_bin=%ld\n", inval[i], cnt,
      //	     ind, median_bin);
    }
  }  
  // now we need an answer, there are 3 different ways we could have it
  //  1) There is just one point, done
  //  2) All the points are the same, done
  //  3) Sort the points that are left and step through for answer
  if (1 == binscnt[median_bin]) { // done
    median = pts_in_bin[0];
  } else {
    for (i=0;i< binscnt[median_bin];i++)
    samenums = 1;
    tmpval = pts_in_bin[0];
    for (i=1;i<binscnt[median_bin]; i++) {
      if (tmpval == pts_in_bin[i]) {
	samenums++;
      } else {
	samenums=0;
	break; // not the case
      }
    }
    if (samenums == binscnt[median_bin]) { // they were all the same
      median = tmpval;
    } else {
      qsort(pts_in_bin, binscnt[median_bin], sizeof(double *), CSPL_Sort_comparedoubles);
      // sum is >= n_med, back off sum by the number in the median bin
      sum -= binscnt[median_bin];
      sum++; // I think this is a zero index things needed
      

      median = pts_in_bin[n_med-sum];
    }
  }

  free(pts_in_bin);
  free(bins);
  free(binscnt);

  return(median);
}




