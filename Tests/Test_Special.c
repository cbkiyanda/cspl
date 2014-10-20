#include <stdio.h>

#include "CSPL_Test.h"
#include "../CSPL/Special/CSPL_Special.h"


int main(void) {

  {
    unsigned long ans[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    unsigned long val, i;
    // test CSPL_Special_factorial()
    printf("Testing: CSPL_Special_factorial()\n");
    for (i=0; i<10;i++){
      val = CSPL_Special_factorial(i);
      assert_long_test(val, ans[i]);
    }

  }
  return(0);
}

