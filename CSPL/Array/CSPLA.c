/** @file
 *
 * Array implementations.
 */

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CSPLA.h"



/**
 * Allocate a 1d CSPLA
 * @param [in] len Length of the of the CSPLA_1d.
 * @param [in] scalar The scalar to add to each element.
 */
void CSPLA_1D_Add_Scalar(CSPLA_1D *arr, /// CSPLA
		      const double scalar /// scalar to add to each
			 ) {
  long i;
  for (i=0;i<arr->n;i++)
    arr->data[i] += scalar;
}

CSPLA_1D *CSPLA_1D_Init(long len) {
  CSPLA_1D *out;
  out =  (CSPLA_1D *)calloc(len, sizeof(CSPLA_1D));
  out->data = (double *)calloc(len, sizeof(double));
  out->n = len;
  return(out);
}

void CSPLA_1D_Free(CSPLA_1D *in) {
  free(in->data);
  free(in);
}

void CSPLA_1D_arange(CSPLA_1D *arr) {
  long i;
  for (i=0;i<arr->n;i++)
    arr->data[i] = i;
}

void CSPLA_1D_print(CSPLA_1D *arr) {
  long i;
  for (i=0;i<arr->n;i++)
    printf("%lf\n", arr->data[i]);
}

void CSPLA_1D_printlong(CSPLA_1D *arr) {
  long i;
  for (i=0;i<arr->n;i++)
    printf("%ld\t%lf\n", i, arr->data[i]);
}



CSPLA *CSPLA_Init(long *sizes, const long ndim) {
  //  CSPLA *out;
  //  void * out;
  long i1,i2,i3,i4,i5,i6,i7,i8,i9;
  // out->data =  (double *)calloc(sizes[0], sizeof(double));
  CSPLA *out;
  long total_len=1;
  long i;

  out = (CSPLA *)calloc(1, sizeof(CSPLA));
  
  for (i=0;i<ndim;i++) {
    total_len *= sizes[i];
  }

  out->total_len = total_len;

  /* printf("Init: total_len = %ld\n", total_len); */
  
  out->data = (double *)calloc(out->total_len, sizeof(double));
  out->sizes = sizes;
  out->ndim = ndim;

  return(out);



  #ifdef BLABLA
  switch(ndim) {
  case 1 :
    {
      CSPLA_1D *out;
      long total_len=1;
      long i;
      out = (CSPLA_1D *)calloc(1, sizeof(CSPLA_1D));

      for (i=0;i<out->n;i++) {
	total_len *= out->sizes[i];
      }
      out->total_len = total_len;

      out = (double *)calloc(out->total_len, sizeof(double));
      out->sizes = sizes;
      out->n = ndim;

      return((CSPLA *)out);
    }
  case 2 :
    {
      CSPLA_2D *out;
      long total_len=1;
      long i;
      for (i=0;i<out->n;i++) {
	total_len *= out->sizes[i];
      }
      out->total_len = total_len;

      out = (CSPLA_2D *)calloc(1, sizeof(CSPLA_2D));
      out->data =  (double **)calloc(sizes[0], sizeof(double));
      out->n = ndim;
      out->sizes = sizes;

      for (i1=0;i1<sizes[1];i1++)  
	out->data[i1] =  (double *)calloc(sizes[1], sizeof(double)); 


      return((CSPLA *)out);
    }

  /* case 2 : */
  /*   //CSPLA_2D *out; */
  /*   (CSPLA_2D*)out->data =  (double *)calloc(sizes[0], sizeof(double)); */
  /*   for (i1=0;i1<sizes[1];i1++)  */
  /*     out->data[i1] =  (double *)calloc(sizes[ndim-1], sizeof(double)); */
  /*   break; */
  /* case 3 : */
  /*   for (i1=0;i1<sizes[1];i1++) { */
  /*     out->data[i1] =  (double *)calloc(sizes[ndim-2], sizeof(double)); */
  /*     for (i2=0;i2<sizes[2];i1++)  */
  /* 	out->data[i1][i2] = (double *)calloc(sizes[ndim-1], sizeof(double)); */
  /*   } */
  /*   break; */
  }
#endif
  //  out->sizes = sizes;
  //return(out);
}

void CSPLA_Free(CSPLA *in) {
  free(in->data);
  free(in);
} 

void CSPLA_arange(CSPLA *arr) {
  long i, j;
  double val=0;

  long total_len=1;

  for (i=0;i<arr->ndim;i++) {
    total_len *= arr->sizes[i];
  }

  /* printf("total_len = %ld\n", total_len); */
  for (i=0;i<total_len;i++) {
    /* printf("** arr->data[%ld] = %lf\n", i, (double)i); */
    arr->data[i] = (double)i;
  }

}

/* typedef struct CSPLA { */
/*   void *data; */
/*   long ndim; */
/*   long *sizes; */
/* } CSPLA; */


