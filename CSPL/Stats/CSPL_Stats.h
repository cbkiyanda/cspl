#ifndef CSPL_Stats_H
#define CSPL_Stats_H

#include "CSPL_Stats_CDF.h"

/* Compute the arithmetic mean of an array */
double CSPL_Stats_mean(double *inval,    // (input) input array 
		 long n);                // (input) length of array

/* Compute the median of an array of doubles */
double CSPL_Stats_median(double *inval, // (input) input array
		    long n);            // (input) length of array

/* Compute the geometric mean of an array of doubles */
double CSPL_Stats_geometric_mean(double *inval, // (input) input array
				long n);        // (input) length of array

/* Compute the variance of an array */
double CSPL_Stats_variance(double *inval,    // (input) input array 
			   long n);                // (input) length of array

/* Compute the standard deviation of an array */
double CSPL_Stats_std(double *inval,    // (input) input array 
		      long n);          // (input) length of array

/* Compute the given percentile of an array using linear interpolation between values*/
/* Title: Sample Quantiles in Statistical Packages */
/* Author(s): Rob J. Hyndman and Yanan Fan */
/* Source: The American Statistician, Vol. 50, No. 4 (Nov., 1996), pp. 361-365 */
/* Stable URL: http://www.jstor.org/stable/2684934 */
double CSPL_Stats_percentile(double *inval,     // (input) input array 
			     double percentile, // the percentile to look for (e.g. 0.2)
			     long n);           // (input) length of array

/* Compute the inner quartile range of an array */
double CSPL_Stats_IQR(double *inval,     // (input) input array 
		      long n);           // (input) length of array

/* Compute the size of histogram bins using the Freedman-Diaconis rule of an array */
double CSPL_Stats_FDrule(double *inval,     // (input) input array 
			 long n);           // (input) length of array

/* compute the percent rank of each measuremnt in an array */
double CSPL_Stats_percent_rank(long n,  // element number (zero based!)
			       long N); // total number of elements


#endif /* CSPL_Stats_H */



