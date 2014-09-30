#ifndef CSPL_Sort_H
#define CSPL_Sort_H
 

/* Function to compare doubles, it is meant to be a stable comparisona also */
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

#endif /* CSPL_Sort_H */



