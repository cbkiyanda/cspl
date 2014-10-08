/** @file
 *
 * Statistics for Normal distribution implementation header.
 */

#ifndef CSPL_Stats_Normal_H
#define CSPL_Stats_Normal_H
 


/*
 * function to return the normal distribution CDF
 * given X, the mean, and stddev (sqrt(variance))
 * this is just the function, one can write another function to return an array
 */
double CSPL_Stats_Normal_CDFfn(const double x,        // (input) position for the CDF
			       const double mean,     // (input) mean of the distribution
			       const double stddev);  // (input) stddev of the distribution (sqrt(variance))


/*
 * function to return the normal distribution quantile as used in testing
 * given F, the mean, and stddev (sqrt(variance))
 * this is just the function, one can write another function to return an array
 */
double CSPL_Stats_Normal_Quantilefn(const double F,         // (input) fraction for the quantile (e.g. 0.95)
				    const double mean,      // (input) mean of the distribution
				    const double stddev);   // (input) stddev of the distribution (sqrt(variance))

#endif /* CSPL_Stats_Normal_H */



