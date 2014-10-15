
// gcc -I../../CSPL/Stats -L../../ descriptive.c -lm -Wall -lCSPL -o descriptive
// install_name_tool -add_rpath ../../ descriptive


#include <stdio.h>

#include "CSPL_Array.h"
#include "CSPL_Stats_Median.h"

int main(void) {
  //  double dat1[5] = {1, 2, 5, 7, 8};
  double dat1[5] = {20, 15, 35, 40, 50};
  double dat2[6] = {1, 2, 2, 6, 7, 8};
  long i;
  double a1;

  printf("dat1:\n");
  for (i=0;i<5;i++)
    printf("  %lf\n", dat1[i]);
  printf("dat2:\n");
  for (i=0;i<6;i++)
    printf("%  lf\n", dat2[i]);


  a1 = CSPL_Array_quickselect(0, dat1, 0, 4);
  printf("CSPL_Array_quickselect(0, dat1, 0, 4)=%lf\n", a1);
  a1 = CSPL_Array_quickselect(1, dat1, 0, 4);
  printf("CSPL_Array_quickselect(1, dat1, 0, 4)=%lf\n", a1);
  a1 = CSPL_Array_quickselect(2, dat1, 0, 4);
  printf("CSPL_Array_quickselect(2, dat1, 0, 4)=%lf\n", a1);
  a1 = CSPL_Array_quickselect(3, dat1, 0, 4);
  printf("CSPL_Array_quickselect(3, dat1, 0, 4)=%lf\n", a1);
  a1 = CSPL_Array_quickselect(4, dat1, 0, 4);
  printf("CSPL_Array_quickselect(4, dat1, 0, 4)=%lf\n", a1);



  return(0);
}

//double CSPL_Array_quickselect(long index, double *inval, long left, long right) {





