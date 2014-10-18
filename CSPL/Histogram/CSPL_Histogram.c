
#include <stdio.h>
#include <stdlib.h>

#include "CSPL_Histogram.h"

/* typedef struct CSPL_Hist { */
/*   long nbins; /// number of bins */
/*   double *edges; /// edges of the bins nbins+1 in length */
/*   long *count; /// number of events in each bin, nbins in length */
/*   long underflow; /// number of elements less than bins */
/*   long overflow; /// number of elements greater than bins */
/*   short uniform; /// Boolean on if the bins are uniform */
/* }CSPL_Hist; */


CSPL_Hist *CSPL_InitHistogram() {
  CSPL_Hist *hist;  
  if ( NULL == (hist = (CSPL_Hist *)calloc(1, sizeof(*hist)) ) ) {
    fprintf(stderr, "CSPL_Init_Hist: malloc failed\n");
    return((CSPL_Hist *)NULL);
  }
  return (hist);
}

short CSPL_Histogram_set_bins(CSPL_Hist *hist, double *edges, long nbins) {
  hist->nbins = nbins;
  hist->edges = edges;
  if ( NULL == (hist->count = (long *)calloc(nbins-1, sizeof(long ))) ) {
    fprintf(stderr, "CSPL_Init_Hist: malloc failed\n");
    return(-1);
  }
  hist->underflow = 0;
  hist->overflow = 0;
  hist->uniform = 0;
  return(0);
}


short CSPL_Histogram_set_uniform(CSPL_Hist *hist, double min, double max, long nbins) {
  hist->nbins = nbins;
  if ( NULL == (hist->edges = (double *)calloc(nbins, sizeof(double ))) ) {
    fprintf(stderr, "CSPL_Init_Hist: malloc failed\n");
    return(-1);
  }
  if ( NULL == (hist->count = (long *)calloc(nbins-1, sizeof(long ))) ) {
    fprintf(stderr, "CSPL_Init_Hist: malloc failed\n");
    return(-1);
  }
  hist->underflow = 0;
  hist->overflow = 0;
  hist->uniform = 1;
  return(0);
}

void CSPL_Free_Hist(CSPL_Hist *hist) {
  printf("h1\n");
  free(hist->count);
  printf("h2\n");
  if (hist->uniform) {
    printf("h3\n");
    free(hist->edges);
  }
  printf("h4\n");
  free(hist);
}
 

