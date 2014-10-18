

#include <stdio.h>

#include "CSPL_Histogram.h"

int main(void) {
  double dat1[15] = {1, 2, 5, 7, 8, 4, 5, 2, 3, 5, 7, 2, 3, 10, 0};
  double edges[5] = {1, 4, 7, 8, 9};
  CSPL_Hist *hist;
  
  printf("Initialize the CSPL_Hist struct\n");
  hist = CSPL_InitHistogram();
  CSPL_Histogram_set_bins(hist, edges, 4);


  printf("Free the CSPL_Hist struct\n");
  CSPL_Free_Hist(hist);

  printf("Initialize the CSPL_Hist struct uniform\n");
  hist = CSPL_InitHistogram();
  CSPL_Histogram_set_uniform(hist, 1, 9, 4);


  printf("Free the CSPL_Hist struct\n");
  CSPL_Free_Hist(hist);
  

  return(0);
}






