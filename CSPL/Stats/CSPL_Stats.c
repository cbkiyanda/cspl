
#include <math.h>   /* log and exp */
#include <stdlib.h> /* qsort */
#include <string.h> /* memcpy */

#include "CSPL_Stats.h"
#include "../Sort/CSPL_Sort.h"



double CSPL_Stats_mean(double *inval, long n) {
  double sum=0;
  long i;

  for (i=0;i<n;i++)
    sum += inval[i];
  return (sum/(double)n);
}

double CSPL_Stats_median(double *inval, long n) {
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

double CSPL_Stats_geometric_mean(double *inval, long n) {
  long i;
  double *incopy; // do this so that the input array is not changed
  double geommean;

  incopy = (double*)calloc(n, sizeof(double));
  memcpy(incopy, inval, sizeof(double)*n);
  
  for (i=0;i<n;i++) {
    incopy[i] = log(incopy[i]);
  }
  geommean = CSPL_Stats_mean(incopy, n);
  free(incopy);  
  return (exp(geommean));
}

/* Compute the variance of an array */
double CSPL_Stats_variance(double *inval,    // (input) input array 
			   long n) {         // (input) length of array
  double mean;
  double variance=0;
  long i;
  mean = CSPL_Stats_mean(inval, n);
  for (i=0;i<n;i++) {
    variance += ( (inval[i] - mean)*(inval[i] - mean));
  }
  return (variance/(double)n);
}

/* Compute the standard deviation of an array */
double CSPL_Stats_std(double *inval,    // (input) input array 
		      long n) {         // (input) length of array
  double variance;
  variance=CSPL_Stats_variance(inval, n);
  return (sqrt(variance));
}

/* Compute the given percentile of an array */
double CSPL_Stats_percentile(double *inval,     // (input) input array 
			     double percentile, // the percentile to look for (e.g. 20)
			     long n) {          // (input) length of array
  /* This uses linear interpolation between the closest ranks to find the value
   * asked for.  
   * see: 
   * Title: Sample Quantiles in Statistical Packages 
   * Author(s): Rob J. Hyndman and Yanan Fan 
   * Source: The American Statistician, Vol. 50, No. 4 (Nov., 1996), pp. 361-365 
   * Stable URL: http://www.jstor.org/stable/2684934 
   */
  
  long i;
  //double *cdf;
  double *incopy;
  double *rank;
  double answer;

  //cdf    = (double*)calloc(n, sizeof(double));
  incopy = (double*)calloc(n, sizeof(double));
  rank   = (double*)calloc(n, sizeof(double));

  memcpy(incopy, inval, sizeof(double)*n);
  qsort(incopy, n, sizeof(double *), CSPL_Sort_comparedoubles);

  // compute the CDF
  //CSPL_Stats_tCDF(inval, cdf, n);

  // compute the rank of each value
  for (i=0;i<n;i++) {
    rank[i] = CSPL_Stats_percent_rank(i, n);
    // check for the special case of percentile outside of data
    if ( (rank[i] > percentile) && (0 == i)) {
      answer = incopy[i];
      break;
    }

    if ( rank[i] == percentile ) { // we are done
      answer = incopy[i];
      break;
    } else 
      if (rank[i] > percentile) { // we have to interpolate (linear)
	answer = inval[i-1] + (n*((percentile-rank[i-1])/100.))*(inval[i] - inval[i-1]);
	break;
      }  
    // if the loop runs all the way through we get the last answer which is correct 
    answer = incopy[i];
  }
  
  //free(cdf);
  free(incopy);
  free(rank);

  return(answer);
}


/* compute the percent rank of each measuremnt in an array */
/* compute the percent rank of each measuremnt in an array */
double CSPL_Stats_percent_rank(long n,  // element number (zero based!)
			       long N) {// total number of elements  // the percent rank is only a function of the number of elements and count
  // the +0.5 is there because we are doing this zero based on the input, 
  //   this means the first element is 0, last is N-1
  return((100./(double)N)*(n+0.5));
}

/* Compute the inner quartile range of an array */
double CSPL_Stats_IQR(double *inval,     // (input) input array 
		      long n) {          // (input) length of array
  double q25, q75;
  q25 = CSPL_Stats_percentile(inval, 25., n); 
  q75 = CSPL_Stats_percentile(inval, 75., n); 
  return(q75-q25);
}

/* Compute the size of histogram bins using the Freedman-Diaconis rule of an array */
double CSPL_Stats_FDrule(double *inval,     // (input) input array 
			 long n) {          // (input) length of array

  return(2.*CSPL_Stats_IQR(inval, n)/pow(n, (1./3.)));
}


