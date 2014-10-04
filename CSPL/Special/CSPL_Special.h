#ifndef CSPL_Special_H
#define CSPL_Special_H

#ifndef CSPL_Sign
#define CSPL_Sign(x) (((x) > 0) ? 1 : ((x < 0) ? -1 : 0))
#endif

/*
 * Compute the error function with a maximal error of  1.5×10−7
 * Abramowitz, Milton, and Irene A. Stegun, eds. Handbook of mathematical functions: with formulas, graphs, 
 * and mathematical tables. No. 55. Courier Dover Publications, 1972.
 */
double CSPL_Special_Erf1(double x); // (input) position to compute the error function




#endif /* CSPL_Special_H */



