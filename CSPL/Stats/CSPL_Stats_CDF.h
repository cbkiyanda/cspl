#ifndef CSPL_Stats_CDF_H
#define CSPL_Stats_CDF_H
 
/* compute the CDF from tabulted data, weights are 1
 *  A random sample of size n from the distrubtion the CDF can be 
 *  estimated empirically from a tabulated data where CDF_n(x) is the
 *  number of observations less than or equal to x divided by n. 
 *  reperated values all have the same CDF value and that value
 *  is the upper (not averaged) probability.
 */
void CSPL_Stats_tCDF(double *datain, /* input array */
		     double *cdfout, /* output CDF (sorted) */
		     long n);        /* array length */



/* Compute confidence bands on the CDF 
 * given a CDF computed from an array compute and return the confidence  
 * bands of the CDF, this is done using the Dvoretzky-Kiefer-Wolfowitz (DKW)  
 * inequality     
 * the conf is the desired confidence, 95% is 0.05, 99% is 0.01   
 */
void CSPL_Stats_tCDF_confidence_bands(double *cdf,         /* input CDF */
				      double *lowerband,   /* lower edges of the confidence band */
				      double *upperband,   /* upper edges of the confidence band */
				      double conf,         /* confidence interval e.g. 0.01 or 0.05 */
				      long n );            /* array length */
 


 
#endif /* CSPL_Stats_CDF_H */



