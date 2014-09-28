#ifndef CSPL_Test_H
#define CSPL_Test_H

#include <math.h>       /* fabs */
#include <stdlib.h>

/* checkmk macro for comparing floats are within a tolerance */
/*  don't forget that the () aroound the args is required if */
/*  the args and just numbers or single calls */ 
#define float_test(v1, v2, tol) fabs( (v1) - (v2) )  < (tol)
 

#endif /* CSPL_Test_H */

