
#include <stdio.h>

#include "../CSPL/Sort/CSPL_Sort.h"
#include "CSPL_Test.h"

/*
 * test the sort
 * just check this by return code
 */
int main(void) {

  {
    double data1[11] = {15, 20, 35, 40, 50, 34, 32, 43, 20,  1, 60};
    double ans[11] =   { 1, 15, 20, 20, 32, 34, 35, 40, 43, 50, 60};
    long i;

    CSPL_Sort_mergesort(data1, 11);
    for (i=0;i<11;i++) {
      printf("CSPL_Sort_mergesort[%ld]=%lf\n", i, data1[i]);
      assert_float_test(ans[i], data1[i], 1e-7);
    }
  }

  return(0);
}



