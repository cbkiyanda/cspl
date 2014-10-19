#include <stdlib.h> /* qsort */
#include <stdio.h>

#include "../Array/CSPL_Array.h"
#include "CSPL_Sort.h"


/** The sort structure.
 */
typedef struct argsort_struct { 
  /** The index. */
  long ind;

  /** The value. */
  double value;
} argsort_struct;

typedef int (*compfn)(const void*, const void*);


static int compare_argsort_struct( argsort_struct *a,  argsort_struct *b);


// from stdlib example docs
int CSPL_Sort_comparedoubles(const void *a, const void *b)
{
  const double *da = (const double *) a;
  const double *db = (const double *) b;

  return (*da > *db) - (*da < *db);
}

static int compare_argsort_struct( argsort_struct *a,  argsort_struct *b)
{
  //const double *da = (const double *) a->value;
  //const double *db = (const double *) b->value;
  return (CSPL_Sort_comparedoubles( (const double *) &a->value, (const double *) &b->value));
  //return (*da > *db) - (*da < *db);
}


/*
 * Given a double array return an array of the indices in order to sort
 * the array
 */
void CSPL_Sort_argsort(double *inval,  /* (input) array to sort */
		       long *outval,   /* (output) array of indices */ 
		       long n) {       /* (input) length of the arrays */
  argsort_struct *vals;
  long i;

  // copy all the input into the structure
  vals = malloc(n * sizeof(argsort_struct));
  for (i=0;i<n;i++) {
    vals[i].ind = i;
    vals[i].value = inval[i];
  }

  // sort the structs
  qsort(vals, n, sizeof(argsort_struct), 
	(compfn)compare_argsort_struct);
  
  // put the inds into the output
  for (i=0;i<n;i++) {
    outval[i] = vals[i].ind;
  }  

  // clean up
  free(vals);

}

/*
 * Implementation of Gnome sort, not one to actually use but interesting as a toy
 * http://xlinux.nist.gov/dads/HTML/gnomeSort.html
 * http://www.dickgrune.com/Programs/gnomesort.html
 * http://en.wikipedia.org/wiki/Gnome_sort algorithm
 */
long CSPL_Sort_gnomesort(double *inval, /* array to be sorted in place */
			 long n) {      /* length of array */
  long pos=1;
  long last=0;
  long nswaps=0;
  while (pos < n) {
    if (inval[pos] >= inval[pos-1]) {
      if (0 != last) {
	pos = last;
	last = 0;
      }
      pos++;
    } else {
      Sort_SWAP(inval[pos], inval[pos-1], double);
      nswaps++;
      if (pos >1) {
	if (0 == last) {
	  last = pos;
	}
	pos--;
      } else {
	pos++;
      }
    }
  }
  return(nswaps);
}

static void merge(double *A, long a, double *B, long b, double *C) {
  int i=0,j=0,k=0;
  while (i < a && j < b) {
    if (A[i] <= B[j]) {
	  /* copy A[i] to C[k] and move the pointer i and k forward */
	  C[k] = A[i];
	  i++;
	  k++;
    }
    else {
      /* copy B[j] to C[k] and move the pointer j and k forward */
      C[k] = B[j];
      j++;
      k++;
    }
  }
  /* move the remaining elements in A into C */
  while (i < a) {
    C[k]= A[i];
    i++;
    k++;
  }
  /* move the remaining elements in B into C */
  while (j < b)  {
    C[k]= B[j];
    j++;
    k++;
  }
}  

void CSPL_Sort_mergesort(double *inval, /* array to be sorted in place */
			 long n) {      /* length of array */
  double *A1, *A2;
  long n1, n2;
  if (n<2)
    return; // only one element is sorted 
  
  n1 = n/2;
  n2 = n-n1;
  //A1 = (double *)calloc(n1, sizeof(double));
  //A2 = (double *)calloc(n2, sizeof(double));
  // first n/2 elements copy from inval to A1
  CSPL_Array_copy(inval, A1, 0, n1, double);
  // the rest go to A1
  CSPL_Array_copy(inval, A2, n1, n, double);
  CSPL_Sort_mergesort(A1, n1);
  CSPL_Sort_mergesort(A2, n2);
  
  // put them together
  merge(A1, n1, A2, n2, inval);
  free(A1);
  free(A2); 
}


#undef Sort_SWAP /* keep this local */


