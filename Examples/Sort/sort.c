
// gcc -I../../CSPL/Sort -L../../ sort.c -lm -Wall -lCSPL -o sort
// install_name_tool -add_rpath ../../ sort


#include <stdio.h>

#include "CSPL_Sort.h"

int main(void) {
  double dat1[5] = {4, 2, 10, 123, 2};
  double dat2[5] = {5, 6, 30, 2, 1};
  long i;
  long inds1[5];
  long inds2[5];


  printf("\n\tArray1\tArray2\n");
  for (i=0;i<5;i++) {
    printf("%5ld\t", i);
    printf("%5.1lf\t", dat1[i]);
    printf("%5.1lf\n", dat2[i]);
  }

  printf("Sort arrays printing out the indicies in argsort\n");
  CSPL_Sort_argsort(dat1, inds1, 5);
  CSPL_Sort_argsort(dat2, inds2, 5);


  for (i=0;i<5;i++) {
    printf("%5ld\t", inds1[i]);
    printf("%5ld\n", inds2[i]);
  }

  {
  double dat1[5] = {4, 2, 10, 123, 2};
  double dat2[5] = {5, 6, 30, 2, 1};

  printf("\n\nDo a mergesort on the arrays\n");
  CSPL_Sort_mergesort(dat1, 5);
  CSPL_Sort_mergesort(dat2, 5);
  printf("\tArray1\tArray2\n");
  for (i=0;i<5;i++) {
    printf("%5ld\t", i);
    printf("%5.1lf\t", dat1[i]);
    printf("%5.1lf\n", dat2[i]);
  }

  }

  return(0);
}






