
#include "CSPL_Array.h"

void CSPL_Array_clip(double *inval,  /* input array to clip  */
		     double min,     /* min value to clip to */
		     double max,     /* max value to clip to */
		     long n) {        /* length of the array */
  long i;
  for (i=0;i<n;i++) {
    inval[i] = (inval[i] < min) ? min : inval[i];
    inval[i] = (inval[i] > max) ? max : inval[i];
  }
}

void test1() {
  int a[4] = {1,2,3,4};
  int b[4] = {1,2,3,4};
  int c[4];
  CSPL_Array_add(a,b,c,4);

}




