

#include <stdio.h>

#include "CSPL_Histogram.h"

int main(void) {
  double dat1[15] = {1, 2, 5, 7, 8, 4, 5, 2, 3, 5, 7, 2, 3, 10, 0};
  
  double edges[5] = {1, 4, 7, 8, 9};
  CSPL_Hist *hist;
  long npts, i;

  printf("Data to bin:\n");
  for (i=0;i<15;i++)
    printf(" %4.1lf", dat1[i] );
  printf("\n\n");

  printf("Initialize the CSPL_Hist struct\n");
  hist = CSPL_InitHistogram();
  CSPL_Histogram_set_bins(hist, edges, 4);

  printf("Add data to bins\n");
  npts = CSPL_Histogram_collect(hist, dat1, 15);
  printf("Edges:\n");
  for (i=0;i<5;i++) {
    printf("%6.1lf", hist->edges[i] );
  }
  printf("\n");
  for (i=0;i<4;i++) {
    printf("   %4ld", hist->count[i] );
  }
  printf("\n");
  printf("npts: %ld under:%ld over:%ld\n",npts, hist->underflow, hist->overflow);

  printf("Free the CSPL_Hist struct\n");
  CSPL_Free_Hist(hist);

  printf("\n\n");
  printf("Initialize the CSPL_Hist struct uniform\n");
  hist = CSPL_InitHistogram();
  CSPL_Histogram_set_uniform(hist, 1, 9, 4);

  printf("Add data to uniform bins\n");
  npts = CSPL_Histogram_collect(hist, dat1, 15);
  printf("Edges:\n");
  for (i=0;i<5;i++) {
    printf("%6.1lf", hist->edges[i] );
  }
  printf("\n");
  for (i=0;i<4;i++) {
    printf("   %4ld", hist->count[i] );
  }
  printf("\n");
  printf("npts: %ld under:%ld over:%ld\n",npts, hist->underflow, hist->overflow);

  printf("Free the CSPL_Hist struct\n");
  CSPL_Free_Hist(hist);
  

  return(0);
}






