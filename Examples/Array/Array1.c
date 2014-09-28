
// gcc -I../../CSPL/Array -L../../ Array1.c -lm -Wall -lCSPL -o Array1
// install_name_tool -add_rpath ../../ Array1


#include <stdio.h>

#include "CSPL_Array.h"

int main(void) {
  double dat1[5] = {1, 2, 5, 7, 8};
  double dat2[5] = {2, 3, 4, 5, 6};
  double dtmp[5];
  long i;

  printf("\nArray1\tArray2\n");
  for (i=0;i<5;i++) {
    printf("%lf\t", dat1[i]);
    printf("%lf\n", dat2[i]);
  }

  CSPL_Array_add(dat1, dat2, dtmp, 5);
  printf("\nSum is:\n");
  for (i=0;i<5;i++) 
    printf("dtmp[%ld]=%lf\n", i, dtmp[i]);

  CSPL_Array_subtract(dat1, dat2, dtmp, 5);
  printf("\nDifference is:\n");
  for (i=0;i<5;i++) 
    printf("dtmp[%ld]=%lf\n", i, dtmp[i]);

  CSPL_Array_multiply(dat1, dat2, dtmp, 5);
  printf("\nProduct is:\n");
  for (i=0;i<5;i++) 
    printf("dtmp[%ld]=%lf\n", i, dtmp[i]);

  CSPL_Array_divide(dat1, dat2, dtmp, 5);
  printf("\nQuotient is:\n");
  for (i=0;i<5;i++) 
    printf("dtmp[%ld]=%lf\n", i, dtmp[i]);

  return(0);
}






