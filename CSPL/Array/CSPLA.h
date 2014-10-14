/** @file
 *
 * Array implementation header.
 */

#ifndef CSPL_Array_H
#define CSPL_Array_H

/************************************************
    TYPES
*************************************************/
typedef struct CSPLA_1D {
  long n;
  long total_len;
  long *sizes;
  double *data;
} CSPLA_1D;

typedef struct CSPLA_2D {
  long n;
  long total_len;
  long *sizes;
  double **data;
} CSPLA_2D;

typedef struct CSPLA_3D {
  double ***data;
  long total_len;
  long n;
} CSPLA_3D;

typedef struct CSPLA_4D {
  double ****data;
  long n;
} CSPLA_4D;

typedef struct CSPLA_5D {
  double *****data;
  long n;
} CSPLA_5D;

typedef struct CSPLA_6D {
  double ******data;
  long n;
} CSPLA_6D;

typedef struct CSPLA_7D {
  double *******data;
  long n;
} CSPLA_7D;

typedef struct CSPLA_8D {
  double ********data;
  long n;
} CSPLA_8D;

/************************************************
    CSPLA PROTOTYPES/MACROS
*************************************************/
/*
 * Add a scalar to each element of a CSPLA
 * @param [inout] arr The CSPLA.
 * @param [in] scalar The scalar to add to each element.
 */
void CSPLA_1D_Add_Scalar(CSPLA_1D *arr, /// CSPLA
		      const double scalar /// scalar to add to each
		      ) ;

CSPLA_1D *CSPLA_1D_Init(long len);

void CSPLA_1D_Free(CSPLA_1D *in);

void CSPLA_1D_arange(CSPLA_1D *arr);

void CSPLA_1D_print(CSPLA_1D *arr);

void CSPLA_1D_printlong(CSPLA_1D *arr);



/************************************************
    CSPLA multi-D try
*************************************************/

typedef struct CSPLA {
  long ndim;
  long total_len;
  long *sizes;
  double *data;
} CSPLA;


CSPLA *CSPLA_Init( long sizes[], const long ndim);

void CSPLA_Free(CSPLA *in);

void CSPLA_arange(CSPLA *arr);


#endif /* CSPL_Array_H */
