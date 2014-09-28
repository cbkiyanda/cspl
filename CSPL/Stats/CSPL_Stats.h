#ifndef CSPL_Stats_H
#define CSPL_Stats_H

/* Compute the arithmetic mean of an array */
double CSPL_Stats_mean(double *inval,    // input array 
		 long n);          // length of array

/* Compute the median of an array of doubles */
double CSPL_Stats_median(double *inval, // input array
		    long n);       // length of array

/* Compute the geometric mean of an array of doubles */
double CSPL_Stats_geometric_mean(double *inval, // input array
				long n);       // length of array

#endif /* CSPL_Stats_H */



