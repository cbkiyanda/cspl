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

