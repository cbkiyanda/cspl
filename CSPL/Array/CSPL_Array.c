
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

double CSPL_Array_range(double *inval, /* input array */
			long n) {      /* length of array */
  double min, max;
  min = CSPL_Array_min(inval, n);
  max = CSPL_Array_max(inval, n);
  return (max-min);
}

void CSPL_Array_filedump1d(const char *filename, long n, int m, ...) {
  FILE *fp;
  int i; // index over number of arrays
  long j; // index over element in array
  va_list ar;
  double **arrs; // these are the arrays we are dumping

  if ((fp = fopen(filename, "w")) == NULL) {
    fprintf(stderr, "%s\n", strerror(ENOENT));
    exit(ENOENT);
  }

  arrs = (double **)calloc(n, sizeof(double));
  // there is already memory for these allocated outside and passed in
  //for (i=0;i<m;i++) {
  //  arrs[i] = (double *)calloc(m, sizeof(double));
  //}

  /* this handles the variadic function part, this is a bit confusing if one has */
  /* not done it bfore so is worth some explanation */
  /* the ... in the definition makes this a variadic function, the int m is the */
  /* number of arguments */
  /* and has to be right before the ... arguments (printf does this as a wrpper where */
  /* the % are counted and passed in as m)  */
  /* the the va_start says grab the args and call them ar, there are m of them */
  /* the the va_arg actually grabs the data for type double* and names it ar */
  /* then it can be used just as a normal pointer */
  /* then the va_end says we are done and cleans up */

  va_start(ar, m);
  // loop over the inut arrays and assign each pointer the the right spot in
  // the 2d array
  for (i=0;i<m;i++) {
    arrs[i] = va_arg(ar, double*);
  }
  va_end(ar);

  // now loop over the 3d array and dump it out
  for (j=0;j<n;j++) {
    for (i=0;i<m;i++) {
      fprintf(fp, "%.6e\t",arrs[i][j]);
    }
    fprintf(fp, "\n");
  }
  
  fclose(fp);

  // free up the memory we allocated
  // for (i=0;i<m;i++) {
  //   free(arrs[i]);
  // }
  free(arrs);
}




