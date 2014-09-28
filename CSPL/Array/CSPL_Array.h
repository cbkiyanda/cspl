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
double CSPL_Array_min(double *inval, /* input array */
		      long n);       /* length of array */

/* return the maximum of an array */
double CSPL_Array_max(double *inval, /* input array */
		      long n);       /* length of array */

/* return the range of an array */
double CSPL_Array_range(double *inval, /* input array */
			long n);       /* length of array */

/* Function to clip an array of doubles to an upper and lower bound */
/* If each element is outside the clip it is replaced with the clip value */
/* replaces the input array with the clipped version */
void CSPL_Array_clip(double *inval,  /* input array to clip  */
		     double min,     /* min value to clip to */
		     double max,     /* max value to clip to */
		     long n);        /* length of the array */


#endif /* CSPL_Array_H */



