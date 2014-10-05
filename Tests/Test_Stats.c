
#include <stdio.h>

#include "../CSPL/Stats/CSPL_Stats.h"
#include "CSPL_Test.h"

/*
 * test the descriptive stats
 * just check this by return code
 */
int main(void) {
  double nCDF;
  double ans;
  // these are taken from scipy.stats.norm
  // should be independently checked
  double data1[11] = {15, 20, 35, 40, 50, 34, 32, 43, 20, 1, 60};
  double skew_ans     =  -0.131700;
  double kurt_ans     =  -0.576756;
  double mean_ans     =  31.818182;
  double median_ans   =  34.000000;
  double std_ans      =  16.078321;
  double variance_ans = 258.512397;

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

  ans = CSPL_Stats_mean(data1, 11);
  if (float_test(ans, mean_ans, 1e-4) == 0) {
    printf("CSPL_Stats_mean=%lf, %lf\n", ans, mean_ans);
    return(1);
  }

  ans = CSPL_Stats_median(data1, 11);
  if (float_test(ans, median_ans, 1e-4) == 0) {
    printf("CSPL_Stats_median=%lf, %lf\n", ans, median_ans);
    return(1);
  }

  ans = CSPL_Stats_std(data1, 11);
  if (float_test(ans, std_ans, 1e-4) == 0) {
    printf("CSPL_Stats_std=%lf, %lf\n", ans, std_ans);
    return(1);
  }

  ans = CSPL_Stats_variance(data1, 11);
  if (float_test(ans, variance_ans, 1e-4) == 0) {
    printf("CSPL_Stats_variance=%lf, %lf\n", ans, variance_ans);
    return(1);
  }

  return(0);
}



