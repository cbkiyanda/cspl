/** @file
 *
 * Array implementations.
 */

#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memcpy */

#include "CSPL_Array.h"
#include "../Special/CSPL_Special.h"  /* CSPL_Sign */
#include "../Sort/CSPL_Sort.h"

/** Clip the elements of an array to within a range (in place, i.e. this
 * function modifies the input array).
 *
 * @f$ A_{i} \leftarrow
 * \left\{ \begin{array}{ll}
 * A_{min} & A_{i} <= A_{min} \\
 * A_{max} & A_{i} >= A_{max} \\
 * A_{i}   & \mbox{otherwise}
 * \end{array} \right. @f$
 *
 * @param [inout] inval The input array.
 * @param [in] min @f$ A_{min} @f$.
 * @param [in] max @f$ A_{max} @f$.
 * @param [in] n The number of elements in the array.
 */
void CSPL_Array_clip(double *inval,  /* input array to clip  */
		     const double min,     /* min value to clip to */
		     const double max,     /* max value to clip to */
		     const long n) {        /* length of the array */
  long i;
  for (i=0;i<n;i++) {
    inval[i] = (inval[i] < min) ? min : inval[i];
    inval[i] = (inval[i] > max) ? max : inval[i];
  }
}

/** Linearly scale the elements of an array to within a range (in place, i.e. this
 * function modifies the input array).
 *
 *
 * @param [inout] inval The input array.
 * @param [in] min @f$ A_{min} @f$.
 * @param [in] max @f$ A_{max} @f$.
 * @param [in] n The number of elements in the array.
 */
void CSPL_Array_scale(double *inval,       /* (in-place) input array to scale  */
		     const double min,     /* (input) min value to scale to */
		     const double max,     /* (input) max value to scale to */
		      const long n) {      /* (input) length of the array */
  double _range = CSPL_Array_range(inval, n);
  double _min   = CSPL_Array_min(inval, n);
  long i;
  for (i=0; i<n;i++) {
    inval[i] -= _min;
    inval[i] /= _range;
    inval[i] *= (max-min);
    inval[i] += min;
  }
}

/** Logarithmically scale the elements of an array to within a range (in place, i.e. this
 * function modifies the input array).
 *
 *
 * @param [inout] inval The input array.
 * @param [in] min @f$ A_{min} @f$.
 * @param [in] max @f$ A_{max} @f$.
 * @param [in] n The number of elements in the array.
 */
void CSPL_Array_logscale(double *inval,       /* (in-place) input array to scale  */
			 const double min,     /* (input) min value to scale to */
			 const double max,     /* (input) max value to scale to */
			 const long n) {      /* (input) length of the array */
  long i;
  CSPL_Array_scale(inval, log10(min), log10(max), n);
  for (i=0;i<n;i++)
    inval[i] = pow(10, inval[i]);
}

/** Return the minimum of an array.
 *
 *
 * @param [in] inval The input array.
 * @param [in] n The number of elements in the array.
 * @return  @f$ A_{min} @f$ , The minimum value of the array.
 */ 
double CSPL_Array_min(const double *inval, /* input array */
		      const long n) {      /* length of array */
  long i;
  double min;
  min = inval[0];
  for (i=1;i<n;i++) {
    min = (inval[i] < min) ? inval[i] : min;
  }
  return (min);
}

/** Return the maximum of an array.
 *
 *
 * @param [in] inval The input array.
 * @param [in] n The number of elements in the array.
 * @return  @f$ A_{max} @f$ , The maximum value of the array.
 */ 
double CSPL_Array_max(const double *inval, /* input array */
		      const long n) {      /* length of array */
  long i;
  double max;
  max = inval[0];
  for (i=1;i<n;i++) {
    max = (inval[i] > max) ? inval[i] : max;
  }
  return (max);
}

/** Return the range of an array.
 *
 *
 * @param [in] inval The input array.
 * @param [in] n The number of elements in the array.
 * @return  @f$ A_{max}A_{min}- @f$ , The range of the array.
 */ 
double CSPL_Array_range(const double *inval, /* input array */
			const long n) {      /* length of array */
  double min, max;
  min = CSPL_Array_min(inval, n);
  max = CSPL_Array_max(inval, n);
  return (max-min);
}

/** Dump a collection of 1-d arrays to a text file. This is meant to be
 * a helper routine, likely wrapped elsewhere. All arrays must be the 
 * same length. 
 *
 *
 * @param [in] filename The filename to create, it is overwritten if it exists.
 * @param [in] n The number of elements in the array.
 * @param [in] m The number of arrays that will be passed in.
 * @param [in] ... the arrays to write out to the file
 */ 
void CSPL_Array_filedump1d(const char *filename, const long n, const int m, ...) {
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
  /* not done it before so is worth some explanation */
  /* the ... in the definition makes this a variadic function, the int m is the */
  /* number of arguments */
  /* and has to be right before the ... arguments (printf does this as a wrapper where */
  /* the % are counted and passed in as m)  */
  /* the the va_start says grab the args and call them ar, there are m of them */
  /* the the va_arg actually grabs the data for type double* and names it ar */
  /* then it can be used just as a normal pointer */
  /* then the va_end says we are done and cleans up */

  va_start(ar, m);
  // loop over the input arrays and assign each pointer the the right spot in
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

/** Compute the value of an index of an array using the quickselect. This is accurate
 * and optimized but cannot add data at a later time
 * Algorithm from:
 * Tibshirani, Ryan J. "Fast computation of the median by successive binning."  
 * arXiv preprint arXiv:0806.3301 (2008). 
 * original reference:
 * Floyd, Robert W., and Ronald L. Rivest. "Algorithm 489: the algorithm 
 * SELECT—for finding the i th smallest of n elements [M1]." Communications
 * of the ACM 18.3 (1975): 173.
 * @param [in] index The desired index value, where array[k] is the (k+1)th smallest element when left = 0.
 * @param [in] inval The input array.
 * @param [in] left Leftmost index of the array to use.
 * @param [in] right Rightmost index of the array to use.
 * @return The value of the median.
 */ 
double CSPL_Array_quickselect(long index, double *inval, long left, long right) {
  double *incopy; // do this so that the input array is not changed
  unsigned long i, j;
  unsigned long k=index; 
  double t, ans;

  // just copy the part we are using
  // this is right-left+1 elements since zero based indexing
  incopy = (double*)calloc(right-left+1, sizeof(double));
  // this is putting (right-left+1) doubles starting at &inval[left] into incopy
  memcpy(incopy, &inval[left], sizeof(double)*(right-left+1));

  while (right > left) {
    t = incopy[k];
    i = left;
    j = right;
    Sort_SWAP(incopy[left], incopy[k], double);
    if (incopy[right] > t)
      Sort_SWAP(incopy[right], incopy[left], double);
    while (i < j) {
      Sort_SWAP(incopy[i], incopy[j], double);
      i++;
      j--;
      while (incopy[i] < t)
	i++;
      while (incopy[j] > t)
	j--;
    }
    if (incopy[left] == t) {
      Sort_SWAP(incopy[left], incopy[j], double);
    } else {
      j++;
      Sort_SWAP(incopy[j], incopy[right], double);
    }
    if (j <= k)
      left = j+1;
    if (k <= j)
      right = j-1;
  }
  ans = incopy[k];
  free(incopy);
  return(ans); 
}

/** Populate an array with linearly scaled elements from min to max.
 *
 * @param [inout] inval The input array.
 * @param [in] min @f$ A_{min} @f$.
 * @param [in] max @f$ A_{max} @f$.
 * @param [in] n The number of elements in the array.
 */
void CSPL_Array_linspace(double *inval,       /* (in-place) input array to populate  */
			 const double min,     /* (input) min value to scale to */
			 const double max,     /* (input) max value to scale to */
			 const long n) {      /* (input) length of the array */
  unsigned long i;
  for (i=0; i<n;i++)
    inval[i] = (double)i;
  CSPL_Array_scale(inval, min, max, n);
}


/** Sum up and array. (double)
 * @param [in] a The array to sum.
 * @param [in] n The number of elements in each array.
 * @return sum The sum of the array.
 */
double CSPL_Array_sum(double *a, unsigned long n)  {
  long i;
  double sum=0;
  for (i=0;i<n;i++) {
    sum += a[i];	
  } 
  return(sum);
}

/** Sum up and array. (long)
 * @param [in] a The array to sum.
 * @param [in] n The number of elements in each array.
 * @return sum The sum of the array.
 */
double CSPL_Array_suml(long *a, unsigned long n)  {
  long i;
  long sum=0;
  for (i=0;i<n;i++) {
    sum += a[i];	
  } 
  return(sum);
}

