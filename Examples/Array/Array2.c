

#include <stdio.h>

#include "CSPL_Array.h"

int main(void) {
  double dat1[5] = {1, 2, 5, 7, 8};
  double dat2[5] = {2, 3, 4, 6, 5};
  double *cpyarray;
  long i;
  const char* filename = "test_dump.csv";

  printf("\nArray1\tArray2\n");
  for (i=0;i<5;i++) {
    printf("%lf\t", dat1[i]);
    printf("%lf\n", dat2[i]);
  }

  CSPL_Array_clip(dat1, 2, 7, 5);
  printf("Clipping Array1 to the range 2-7\n");
  for (i=0;i<5;i++)
    printf("%lf\n",dat1[i]);
    
  CSPL_Array_clip(dat2, 3, 20, 5);
  printf("Clipping Array2 to the range 3-20\n");
  for (i=0;i<5;i++)
    printf("%lf\n",dat2[i]);

  
  printf("\nDumping Array1 and Array2 into a csv file named %s\n", filename);

  CSPL_Array_filedump1d(filename, 5, 2, dat1, dat2);

  {
  double dat1[5] = {1, 2, 5, 7, 8};

  printf("\n\nCopying a subarray from original dat1\n");
  CSPL_Array_copy(dat1, cpyarray, 1, 4, double);

  for (i=0;i<3;i++)
    printf("cpyarray[%ld]=%lf\n", i, cpyarray[i]);
  free(cpyarray);

  }
  return(0);
}






