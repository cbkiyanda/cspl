/** @file
 *
 * Statistics to compute and use cumulative probability distributions (CDF).
 */

#ifndef CSPL_Stats_CDF_H
#define CSPL_Stats_CDF_H
 
/* compute the CDF from tabulated data, weights are 1
 *  A random sample of size n from the distribution the CDF can be 
 *  estimated empirically from a tabulated data where CDF_n(x) is the
 *  number of observations less than or equal to x divided by n. 
 *  repeated values all have the same CDF value and that value
 *  is the upper (not averaged) probability.
 */
void CSPL_Stats_tCDF(const double *datain, /* (input) input array */
		     double *cdfout, /* (output) output CDF (sorted) */
		     const long n);        /* (input) array length */



/* Compute confidence bands on the CDF 
 * given a CDF computed from an array compute and return the confidence  
 * bands of the CDF, this is done using the Dvoretzky-Kiefer-Wolfowitz (DKW)  
 * inequality     
 * the conf is the desired confidence, 95% is 0.05, 99% is 0.01   
 */
void CSPL_Stats_tCDF_confidence_bands(const double *cdf,         /* (input) input CDF */
				      double *lowerband,   /* (output) lower edges of the confidence band */
				      double *upperband,   /* (output) upper edges of the confidence band */
				      const double conf,         /* (input) confidence interval e.g. 0.01 or 0.05 */
				      const long n );            /* (input) array length */
 


 
#endif /* CSPL_Stats_CDF_H */



