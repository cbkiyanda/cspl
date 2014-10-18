
#include <stdio.h>

#include "CSPL_Array.h"

int main(void) {
  double dat1[5] = {1, 2, 5, 7, 8};
  long ans, i;
  double val;
  
  for (i=0; i<5; i++)
    printf("dat1[%ld]=%lf\n", i, dat1[i]);

  val = -1;
  ans = CSPL_Array_bisect(val, dat1, 5);
  printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);

  val = 1.5;
  ans = CSPL_Array_bisect(val, dat1, 5);
  printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);

  val = 5.0;
  ans = CSPL_Array_bisect(val, dat1, 5);
  printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);

  val = 5.5;
  ans = CSPL_Array_bisect(val, dat1, 5);
  printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);

  val = 8.5;
  ans = CSPL_Array_bisect(val, dat1, 5);
  printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);


  return(0);
}






