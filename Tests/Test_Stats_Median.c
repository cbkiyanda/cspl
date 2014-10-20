
#include <stdio.h>
#include <time.h>

#include "../CSPL/Stats/CSPL_Stats.h"
#include "CSPL_Test.h"


/*
 * test the normal distribution functions
 * just check this by return code
 */
int main(void) {
  double dat1[5] = {15, 20, 35, 40, 50};
  clock_t start;
  double a1, a2, a3;
  
  start = clock(); // rough but lets see
  a1 =  CSPL_Stats_median_sort(dat1, 5);
  printf("median1_sort: %lf  -- %ld ticks\n", 
	 a1,
	 (clock() - start));
  start = clock(); // rough but lets see

  a2 = CSPL_Stats_median_quickselect(dat1, 5);
  printf("median1_quick: %lf  -- %ld ticks\n", 
	 a2, 
	 (clock() - start));
  start = clock(); // rough but lets see

  a3 = CSPL_Stats_median_bin(dat1, 5);
  printf("CSPL_Stats_median_bin: %lf  -- %ld ticks\n", 
	 a3, 
	 (clock() - start));

  assert_float_test(a1, a2, 1e-5);
  assert_float_test(a1, a3, 1e-5);
  assert_float_test(a2, a3, 1e-5);
  assert_float_test(a1, 35.0, 1e-5);


  printf("--------------------\n");

  {
    
    double *dat1;
    long c;
    long lens[3]={101, 1000001, 2000};
    double ans[3] = {39, 51, 52};
    long len;

    for (len=0; len<3; len++) {
      dat1 = (double *)calloc(lens[len], sizeof(double));

      srand(123);
      for (c = 0; c < lens[len]; c++) {
	dat1[c] = rand()%100 + 1;
      }
      
      a1 = CSPL_Stats_median_sort(dat1, lens[len]);
      printf("Repeat for %ld random numbers from 0 to 100\n", lens[len]);
      CSPL_Stats_median_bin(dat1, lens[len]);
      start = clock(); // rough but lets see
      printf("CSPL_Stats_median_sort: %lf  -- %ld ticks\n", 
	     a1, 
	     (clock() - start));

      start = clock(); // rough but lets see
      a2 = CSPL_Stats_median_quickselect(dat1, lens[len]);
      printf("CSPL_Stats_median_quickselect: %lf  -- %ld ticks\n", 
	     a2, 
	     (clock() - start));

      start = clock(); // rough but lets see
      a3 = CSPL_Stats_median_quickselect(dat1, lens[len]);
      printf("CSPL_Stats_median_bin: %lf  -- %ld ticks\n", 
	     a3, 
	     (clock() - start));


      assert_float_test(a1, a2, 1e-5);
      assert_float_test(a1, a3, 1e-5);
      assert_float_test(a2, a3, 1e-5);
      assert_float_test(a1, ans[len], 1e-5);
      
      free(dat1);
      printf("--------------------\n");
    }
  }

  return(0);

}



