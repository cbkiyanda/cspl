#include <stdio.h>

#include "CSPL_Test.h"
#include "../CSPL/Regression/CSPL_Regression.h"


int main(void) {
  {
    // Test CSPL_Regression_TheilSen
    double x[10] = {1,2,3,4,5,6,7,8,9, 10};
    double y[10] = {0.86074211,  2.243673  ,  2.32922599,  3.5269751 ,  5.19649183,
		    4.55875795,  8.6822283 ,  7.86981641,  9.0570581 ,  7.766994};
    long i;
    double slope, intercept;
    
    CSPL_Regression_TheilSen(x, y, 10, &slope, &intercept);
    
    printf("%10s\t%10s\n", "x", "y");
    for (i=0; i<10; i++) {
      printf("%10.2lf\t%10.2lf\n", x[i], y[i]);
    }
    printf("\n");
    printf("Slope: %lf, Intercept=%lf\n", slope, intercept);
    assert_float_test(slope, 0.965142, 1e-6);
    assert_float_test(intercept, 0.022142, 1e-6);
    
  }
  return(0);
}

