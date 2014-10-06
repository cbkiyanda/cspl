
#include <stdio.h>

#include "../CSPL/Stats/CSPL_Stats.h"
#include "CSPL_Test.h"

/*
 * test the normal distribution functions
 * just check this by return code
 */
int main(void) {
  double nCDF;
  double quan;
  long i;
  double ans;
  // these are taken from scipy.stats.norm
  // should be independently checked
  double nCDF_ans[7] = {0.001349898 ,  0.022750132,  
			0.15865525,  0.5       ,  
			0.84134475,  0.97724987,  
			0.9986501};
  double nCDF_ins[7] = {-3.0, -2.0, -1.0 , 0.0,
			 1.0,  2.0,  3.0};
  double Quantile_ans[1] = {1.96};
  double Quantile_ins[1] = {0.975};


  for (i=0;i<7;i++) {
    ans = CSPL_Stats_Normal_CDFfn(nCDF_ins[i], 0.0, 1.0);
    printf("CSPL_Stats_Normal_CDFfn(%lf) %lf != %lf\n", 
	   nCDF_ins[i], ans, nCDF_ans[i]);
    assert_float_test(ans, nCDF_ans[i], 1e-4);
  }

  for (i=0;i<1;i++) {
    ans = CSPL_Stats_Normal_Quantilefn(Quantile_ins[i], 0.0, 1.0);
    printf("CSPL_Stats_Normal_Quantilefn(%lf) %lf != %lf\n", 
	   Quantile_ins[i], ans, Quantile_ans[i]);
    assert_float_test(ans, Quantile_ans[i], 1e-2);
  }
  
  return(0);


}



