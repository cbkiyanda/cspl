/** @file
 *
 * Histogram implementation header.
 */

#ifndef CSPL_Histogram_H
#define CSPL_Histogram_H


/************************************************
    TYPES
*************************************************/
typedef struct CSPL_Hist {
  long nbins; /// number of bins
  double *edges; /// edges of the bins nbins+1 in length
  long *count; /// number of events in each bin, nbins in length
  long underflow; /// number of elements less than bins
  long overflow; /// number of elements greater than bins
  short uniform; /// Boolean on if the bins are uniform
  long npts;
}CSPL_Hist;

/************************************************
    MACROS
*************************************************/

/************************************************
    PROTOTYPES
*************************************************/
CSPL_Hist * CSPL_InitHistogram();
short CSPL_Histogram_set_bins(CSPL_Hist *hist, double *edges, long nbins);
short CSPL_Histogram_set_uniform(CSPL_Hist *hist, double min, double max, long nbins);
long CSPL_Histogram_collect(CSPL_Hist *hist, double *data, long len);

void CSPL_Free_Hist(CSPL_Hist *hist);



#endif /* CSPL_Histogram_H */


