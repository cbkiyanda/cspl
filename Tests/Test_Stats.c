
#include <stdio.h>

#include "../CSPL/Stats/CSPL_Stats.h"
#include "CSPL_Test.h"

/*
 * test the descriptive stats
 * just check this by return code
 */
int main(void) {
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
  double geo_ans      = 23.449640;

  ans = CSPL_Stats_skew(data1, 11);
  printf("CSPL_Stats_skew=%lf, %lf\n", ans, skew_ans);
  assert_float_test(ans, skew_ans, 1e-4);

  ans = CSPL_Stats_kurtosis(data1, 11);
  printf("CSPL_Stats_kurtosis=%lf, %lf\n", ans, kurt_ans);
  assert_float_test(ans, kurt_ans, 1e-4);
 
  ans = CSPL_Stats_mean(data1, 11);
  printf("CSPL_Stats_mean=%lf, %lf\n", ans, mean_ans);
  assert_float_test(ans, mean_ans, 1e-4);

  ans = CSPL_Stats_median_sort(data1, 11);
  printf("CSPL_Stats_median_sort=%lf, %lf\n", ans, median_ans);
  assert_float_test(ans, median_ans, 1e-4);

  ans = CSPL_Stats_std(data1, 11);
  printf("CSPL_Stats_std=%lf, %lf\n", ans, std_ans);
  assert_float_test(ans, std_ans, 1e-4);

  ans = CSPL_Stats_variance(data1, 11);
  printf("CSPL_Stats_variance=%lf, %lf\n", ans, variance_ans);
  assert_float_test(ans, variance_ans, 1e-4);

  ans = CSPL_Stats_geometric_mean(data1, 11);
  printf("CSPL_Stats_geometric_mean=%lf, %lf\n", ans, geo_ans);
  assert_float_test(ans, geo_ans, 1e-4);

  {
    double data[5] = {2,3.4, 5.6, 4.5, 3.1};
    double outval[5];
    double answer[5] = {0.2, 0.4, 0.6, 0.8, 1.0};
    long i;
    CSPL_Stats_tCDF(data, outval, 5);
    for (i=0;i<5;i++) {
      assert_float_test(outval[i], answer[i], 1e-5);
    }
  }
  {
    double data[5] =  {0.2, 0.4, 0.6, 0.8, 1.0};
    double outval1[5];
    double outval2[5];
    double answer1[5] = {0.0, 0.0, 0.0, 0.072105, 0.272105};
    double answer2[5] = {0.927895, 1.0, 1.0, 1.0, 1.0};
    long i;
    CSPL_Stats_tCDF_confidence_bands(data, outval1, outval2, 0.01, 5);
    /* for (i=0;i<5;i++) {
    // printf("%lf\t%lf\n", outval1[i], outval2[i]);
    } */
    for (i=0;i<5;i++) {
      assert_float_test(outval1[i], answer1[i], 1e-5);
      assert_float_test(outval2[i], answer2[i], 1e-5);
    }	  
  }
  {
    double data[5] =  {0.2, 0.4, 0.6, 0.8, 1.0};
    printf("CSPL_Stats_percentile %lf\n", CSPL_Stats_percentile(data, 20, 5));
    assert_float_test(CSPL_Stats_percentile(data, 20, 5), 0.300000, 1e-5);
    printf("CSPL_Stats_percentile %lf\n", CSPL_Stats_percentile(data, 25, 5));
    assert_float_test(CSPL_Stats_percentile(data, 25, 5), 0.350000, 1e-5);
    printf("CSPL_Stats_percentile %lf\n", CSPL_Stats_percentile(data, 40, 5));
    assert_float_test(CSPL_Stats_percentile(data, 40, 5), 0.500000, 1e-5);
    printf("CSPL_Stats_percentile %lf\n", CSPL_Stats_percentile(data, 50, 5));
    assert_float_test(CSPL_Stats_percentile(data, 50, 5), 0.600000, 1e-5);
    printf("CSPL_Stats_percentile %lf\n", CSPL_Stats_percentile(data, 60, 5));
    assert_float_test(CSPL_Stats_percentile(data, 60, 5), 0.700000, 1e-5);
    printf("CSPL_Stats_percentile %lf\n", CSPL_Stats_percentile(data, 82, 5));
    assert_float_test(CSPL_Stats_percentile(data, 82, 5), 0.920000, 1e-5);
    assert_float_test(CSPL_Stats_percentile(data, 50, 5), CSPL_Stats_median_sort(data, 5) , 1e-5);
  }
  {
    long N=11;
    long n;
    double answer[11] = {4.545455, 13.636364, 22.727273, 31.818182, 40.909091, 
			 50.000000, 59.090909, 68.181818, 77.272727, 86.363636, 
			 95.454545};
    for (n=0;n<N;n++) {
      printf("CSPL_Stats_percent_rank %ld, %ld, %lf\n", n, N, CSPL_Stats_percent_rank(n, N));
      assert_float_test(CSPL_Stats_percent_rank(n, N), answer[n] , 1e-5);
    }	
  }

  return(0);
}



