/** @file
 *
 * Header file for CSPL_Sort.
 */

#ifndef CSPL_Sort_H
#define CSPL_Sort_H

#define Sort_SWAP(a,b,type) {type tmp=a;a=b;b=tmp;}


/* Function to compare doubles, it is meant to be a stable comparison also */
/* from stdlib example docs */
/* mainly used in stdlib.h qsort */
int CSPL_Sort_comparedoubles(const void *a,  /* (input) first double  */
			     const void *b); /* (input) second double */

/*
 * Given a double array return an array of the indices in order to sort
 * the array
 */
void CSPL_Sort_argsort(double *inval, /* (input) array to sort */
		       long *outval,  /* (output) array of indicies */
		       long n);       /* (input) length of the arrays */

/*
 * Implementation of Gnome sort, not one to actually use but interesting as a toy
 * http://xlinux.nist.gov/dads/HTML/gnomeSort.html
 * http://www.dickgrune.com/Programs/gnomesort.html
 * http://en.wikipedia.org/wiki/Gnome_sort algorithm
 *
 * return the number of swaps performed
 */
long CSPL_Sort_gnomesort(double *inval, /* array to be sorted in place */
			 long n);       /* length of array */

/*
 * Implementation of mergesort (top down)
 *
 */
void CSPL_Sort_mergesort(double *inval, /* array to be sorted in place */
			 long n);       /* length of array */


#endif /* CSPL_Sort_H */
