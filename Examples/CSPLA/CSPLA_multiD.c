
#include <stdio.h>
#include <stdlib.h>

#include "CSPLA.h"

int main(void) {
  double dat1[5] = {1, 2, 5, 7, 8};
  double dat2[5] = {2, 3, 4, 6, 5};
  double dtmp[5];
  double v1,v2;
  long i;
  CSPLA *arr;

  {
  CSPLA *arr;
  long sizes[1] = {10};
  printf("/////////////////////////\n");
  printf("Demonstrating CSPLA 1D \n");
  printf("/////////////////////////\n");

  arr = CSPLA_Init(sizes, 1);

  CSPLA_arange(arr);

  for (i=0;i<arr->total_len;i++)
    printf("arr->data[%ld]=%lf\n", i, arr->data[i] );

  CSPLA_Free(arr);

  }

 {
  CSPLA *arr;
  long sizes[2] = {10,2};
  printf("/////////////////////////\n");
  printf("Demonstrating CSPLA 2D \n");
  printf("/////////////////////////\n");

  arr = CSPLA_Init(sizes, 2);

  CSPLA_arange(arr);

  for (i=0;i<arr->total_len;i++)
    printf("arr->data[%ld]=%lf\n", i, arr->data[i] );

  CSPLA_Free(arr);

  }


  return(0);
}






