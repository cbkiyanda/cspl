
// gcc -I../../CSPL/Stats -L../../ descriptive.c -lCSPL -o descriptive

#include <stdio.h>

#include "CSPL_Stats_CDF.h"
#include "CSPL_Stats.h"

int main(void) {
  double dat1[5] = {1, 2, 5, 7, 8};
  double dat2[6] = {1, 2, 2, 6, 7, 8};
  long i;
  
  for (i=0;i<5;i++) 
    printf("dat1[%ld]=%lf\n", i, dat1[i]);
  printf("\n");
  for (i=0;i<6;i++) 
    printf("dat2[%ld]=%lf\n", i, dat1[i]);
  
  printf("mean1: %lf\n", CSPL_mean(dat1, 5));
  printf("mean2: %lf\n", CSPL_mean(dat2, 6));

  printf("median1: %lf\n", CSPL_median(dat1, 5));
  printf("median2: %lf\n", CSPL_median(dat2, 6));


  return(0);
}






