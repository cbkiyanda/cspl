
#include <stdio.h>

#include "CSPLA.h"

int main(void) {
  double dat1[5] = {1, 2, 5, 7, 8};
  double dat2[5] = {2, 3, 4, 6, 5};
  double dtmp[5];
  double v1,v2;
  long i;
  CSPLA_1D *arr;

  printf("/////////////////////////\n");
  printf("Demonstrating CSPLA\n");
  printf("/////////////////////////\n");
  printf("**  CSPLA_1D_Init(10) **\n");
  printf("** CSPLA_1D_arange(arr) **\n");
  printf("** CSPLA_1D_printlong(arr) **\n");
  // probably want a maker soon
  
  arr = CSPLA_1D_Init(10);

  CSPLA_1D_arange(arr);
  CSPLA_1D_printlong(arr);

  /* CSPL_Array_logscale(dat2, 1, 10, 5); */
  /* printf("\nLog Scaled to [1,10] gives:\n"); */
  /* for (i=0;i<5;i++)  */
  /*   printf("dat2[%ld]=%lf\n", i, dat2[i]); */

  printf("** CSPLA_1D_Free(arr) **\n");

  CSPLA_1D_Free(arr);

  return(0);
}






