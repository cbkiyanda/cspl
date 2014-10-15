/** @file
 *
 * Array implementation header.
 */

#ifndef CSPL_Array_H
#define CSPL_Array_H


/************************************************
    MACROS
*************************************************/

/*
 * typesafety, 
 * http://stackoverflow.com/questions/3437404/min-and-max-in-c
 */
#define array_max(a,b) \
  ({ __typeof__ (a) _a = (a);	\
    __typeof__ (b) _b = (b);	\
    _a > _b ? _a : _b; })

#define array_min(a,b) \
  ({ __typeof__ (a) _a = (a);	\
    __typeof__ (b) _b = (b);	\
    _a < _b ? _a : _b; })



/**
 * \def CSPL_Array_add(a, b, c, n)
 * Macro to add two arrays of the same type element by element. a+b=c for arrays of a given type

 * @param [in] a The first array.
 * @param [in] b The second array.
 * @param [inout] c Output array @f$ a+b @f$ must be preallocated.
 * @param [in] n The number of elements in each array.
 */
#define CSPL_Array_add(a, b, c, n)  {		\
         long i;	       			\
         for (i=0;i<n;i++) {	       		\
	   c[i] = a[i] + b[i];		       	\
         }                                      \
}

/**
 * \def CSPL_Array_subtract(a, b, c, n)
 * Macro to subtract two arrays of the same type element by element. a-b=c for arrays of a given type

 * @param [in] a The first array.
 * @param [in] b The second array.
 * @param [inout] c Output array @f$ a-b @f$ must be preallocated.
 * @param [in] n The number of elements in each array.
 */
#define CSPL_Array_subtract(a, b, c, n)  {	\
         long i;	       			\
         for (i=0;i<n;i++) {	       		\
	   c[i] = a[i] - b[i];		       	\
         }                                      \
}
 
/**
 * \def CSPL_Array_multiply(a, b, c, n)
 * Macro to multiply two arrays of the same type element by element. a*b=c for arrays of a given type

 * @param [in] a The first array.
 * @param [in] b The second array.
 * @param [inout] c Output array @f$ a*b @f$ must be preallocated.
 * @param [in] n The number of elements in each array.
 */
#define CSPL_Array_multiply(a, b, c, n)  {	\
         long i;	       			\
         for (i=0;i<n;i++) {	       		\
	   c[i] = a[i] * b[i];		       	\
         }                                      \
}

/**
 * \def CSPL_Array_divide(a, b, c, n)
 * Macro to divide two arrays of the same type element by element. a/b=c for arrays of a given type

 * @param [in] a The first array.
 * @param [in] b The second array.
 * @param [inout] c Output array @f$ a/b @f$ must be preallocated.
 * @param [in] n The number of elements in each array.
 */
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

/* Function to linearly scale an array of doubles between an upper and lower bound */
/* replaces the input array with the scaled version */
void CSPL_Array_scale(double *inval,  /* (in-place) input array to scale  */
		     const double min,     /* (input) min value to scale to */
		     const double max,     /* (input) max value to scale to */
		     const long n);        /* (input) length of the array */

/* Function to logarithmically scale an array of doubles between an upper and lower bound */
/* replaces the input array with the scaled version */
void CSPL_Array_logscale(double *inval,  /* (in-place) input array to scale  */
			 const double min,     /* (input) min value to scale to */
			 const double max,     /* (input) max value to scale to */
			 const long n);        /* (input) length of the array */


double CSPL_Array_quickselect(long index, double *inval, long left, long right);


#endif /* CSPL_Array_H */
