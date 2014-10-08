#ifndef CSPL_Array_H
#define CSPL_Array_H

/************************************************
    MACROS
*************************************************/

/* Perform a+b=c for arrays of a given type, they should all be the same type */
#define CSPL_Array_add(a, b, c, n)  {		\
         long i;	       			\
         for (i=0;i<n;i++) {	       		\
	   c[i] = a[i] + b[i];		       	\
         }                                      \
}

/* Perform a-b=c for arrays of a given type, they should all be the same type */
#define CSPL_Array_subtract(a, b, c, n)  {	\
         long i;	       			\
         for (i=0;i<n;i++) {	       		\
	   c[i] = a[i] - b[i];		       	\
         }                                      \
}
 
/* Perform a*b=c for arrays of a given type, they should all be the same type */
#define CSPL_Array_multiply(a, b, c, n)  {	\
         long i;	       			\
         for (i=0;i<n;i++) {	       		\
	   c[i] = a[i] * b[i];		       	\
         }                                      \
}

/* Perform a/b=c for arrays of a given type, they should all be the same type */
#define CSPL_Array_divide(a, b, c, n)  {	\
         long i;	       			\
         for (i=0;i<n;i++) {	       		\
	   c[i] = a[i] / b[i];		       	\
         }                                      \
}

/************************************************
    PROTOTYPES
*************************************************/
/* return the minimum of an array */
double CSPL_Array_min(const double *inval, /* (input) input array */
		      const long n);       /* (input) length of array */

/* return the maximum of an array */
double CSPL_Array_max(const double *inval, /* (input) input array */
		      const long n);       /* (input) length of array */

/* return the range of an array */
double CSPL_Array_range(const double *inval, /* (input) input array */
			const long n);       /* (input) length of array */

/* Function to clip an array of doubles to an upper and lower bound */
/* If each element is outside the clip it is replaced with the clip value */
/* replaces the input array with the clipped version */
void CSPL_Array_clip(double *inval,  /* (in-place) input array to clip  */
		     const double min,     /* (input) min value to clip to */
		     const double max,     /* (input) max value to clip to */
		     const long n);        /* (input) length of the array */

/* Variadic function to dump out some number of arrays of the same length to CSV */
void CSPL_Array_filedump1d(const char *filename,  /* (input) filename to output to, overwritten */
			   const long n,                /* (input) length of each array (all have to be the same) */
			   const int m,                 /* (input) number of arrays to dump */
			   ...);                  /* (input) the arrays */


#endif /* CSPL_Array_H */



