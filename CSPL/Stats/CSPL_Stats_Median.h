#ifndef CSPL_Stats_MEDIAN_H
#define CSPL_Stats_MEDIAN_H


#define CSPL_Stats_median CSPL_Stats_median_quickselect


/* Implementaion from: */
/* Tibshirani, Ryan J. "Fast computation of the median by successive binning."  */
/* arXiv preprint arXiv:0806.3301 (2008). */


/* Compute the median of an array of doubles */
double CSPL_Stats_median_sort(double *inval, long n);

/* Compute the median of an array of doubles */
double CSPL_Stats_median_quickselect(double *inval, const long n);

/* Compute the median of an array of doubles */
double CSPL_Stats_median_bin(double *inval, const long n);



#endif /* CSPL_Stats_MEDIAN_H */


