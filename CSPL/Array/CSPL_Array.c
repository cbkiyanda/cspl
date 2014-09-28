
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

double CSPL_Array_min(double *inval, /* input array */
		      long n) {      /* length of array */
  long i;
  double min;
  min = inval[0];
  for (i=1;i<n;i++) {
    min = (inval[i] < min) ? inval[i] : min;
  }
  return (min);
}

double CSPL_Array_max(double *inval, /* input array */
		      long n) {      /* length of array */
  long i;
  double max;
  max = inval[0];
  for (i=1;i<n;i++) {
    max = (inval[i] > max) ? inval[i] : max;
  }
  return (max);
}



