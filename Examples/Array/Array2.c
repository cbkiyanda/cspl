
// gcc -I../../CSPL/Array -L../../ Array2.c -lm -Wall -lCSPL -o Array2
// install_name_tool -add_rpath ../../ Array2


#include <stdio.h>

#include "CSPL_Array.h"

int main(void) {
  double dat1[5] = {1, 2, 5, 7, 8};
  double dat2[5] = {2, 3, 4, 6, 5};
  long i;

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


  return(0);
}






