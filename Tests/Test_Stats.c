
#include <stdio.h>

#include "../CSPL/Stats/CSPL_Stats.h"
#include "CSPL_Test.h"

/*
 * test the descriptive stats
 * just check this by return code
 */
int main(void) {
  double nCDF;
  double quan;
  long i;
  double ans;
  // these are taken from scipy.stats.norm
  // should be independently checked
  double data1[11] = {15, 20, 35, 40, 50, 34, 32, 43, 20, 1, 60};
  double skew_ans = -0.131700;
  double kurt_ans = -0.576756;

  ans = CSPL_Stats_skew(data1, 11);
  if (float_test(ans, skew_ans, 1e-4) == 0) {
    printf("CSPL_Stats_skew=%lf, %lf\n", ans, skew_ans);
    return(1);
  }

  ans = CSPL_Stats_kurtosis(data1, 11);
  if (float_test(ans, kurt_ans, 1e-4) == 0) {
    printf("CSPL_Stats_kurtosis=%lf, %lf\n", ans, kurt_ans);
    return(1);
  }


  return(0);
}



