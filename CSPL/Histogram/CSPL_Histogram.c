
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "../Array/CSPL_Array.h"
#include "CSPL_Histogram.h"

CSPL_Hist *CSPL_InitHistogram() {
  CSPL_Hist *hist;  
  if ( NULL == (hist = (CSPL_Hist *)calloc(1, sizeof(*hist)) ) ) {
    fprintf(stderr, "CSPL_Init_Hist: malloc failed\n");
    return((CSPL_Hist *)NULL);
  }
  hist->underflow = 0;
  hist->overflow = 0;
  hist->uniform = 0;
  hist->npts = 0;
  return (hist);
}

short CSPL_Histogram_set_bins(CSPL_Hist *hist, double *edges, long nbins) {
  long i;
  hist->nbins = nbins;
  hist->edges = edges;

  if ( NULL == (hist->count = (long *)calloc(nbins, sizeof(long ))) ) {
    fprintf(stderr, "CSPL_Init_Hist: malloc failed\n");
    return(-1);
  }

  return(0);
}


short CSPL_Histogram_set_uniform(CSPL_Hist *hist, double min, double max, long nbins) {
  hist->nbins = nbins;
  if ( NULL == (hist->edges = (double *)calloc(nbins+1, sizeof(double ))) ) {
    fprintf(stderr, "CSPL_Init_Hist: malloc failed\n");
    return(-1);
  }

  CSPL_Array_linspace(hist->edges, min, max, nbins+1);

  if ( NULL == (hist->count = (long *)calloc(nbins, sizeof(long ))) ) {
    fprintf(stderr, "CSPL_Init_Hist: malloc failed\n");
    return(-1);
  }

  hist->uniform = 1;
  return(0);
}

// edge1 <= val < edge
long CSPL_Histogram_collect(CSPL_Hist *hist, double *data, long len) {
  long nadded=0;
  long ind, i;
  /*
   * if uniform is not set we have to find the right bin, 
   * otherwise we can be a bit tricky with math (not yet implemented)
   */ 
  for (i=0;i<len;i++) {
    // find the index to increment
    if (data[i] < hist->edges[0]) {
      hist->underflow++;
      nadded++;
    } else if (data[i] >= hist->edges[hist->nbins]) { // as an index this is correct
      hist->overflow++;
      nadded++;
    } else {
      ind = CSPL_Array_bisect(data[i], hist->edges, hist->nbins+1)-1;
      hist->count[ind]++;
      nadded++;
      }
  }

  return(nadded);
}


void CSPL_Free_Hist(CSPL_Hist *hist) {
  free(hist->count);
  if (hist->uniform) {
    free(hist->edges);
  }
  free(hist);
}
 

