
#include <stdlib.h> /* qsort */

#include "CSPL_Sort.h"


#define Sort_SWAP(a,b,type) {type tmp=a;a=b;b=tmp;}


typedef struct argsort_struct { 
  long ind;
  double value;
} argsort_struct;

typedef int (*compfn)(const void*, const void*);


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
		       long *outval,   /* (output) array of indicies */ 
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

#undef Sort_SWAP /* keep this local */


