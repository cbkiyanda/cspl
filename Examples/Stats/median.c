
// gcc -I../../CSPL/Stats -L../../ descriptive.c -lm -Wall -lCSPL -o descriptive
// install_name_tool -add_rpath ../../ descriptive


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "CSPL_Stats.h"
#include "CSPL_Stats_Median.h"

int main(void) {
  double dat1[5] = {15, 20, 35, 40, 50};
  long i;
  clock_t start;
  
  for (i=0;i<5;i++) 
    printf("dat1[%ld]=%lf\n", i, dat1[i]);
  printf("\n");
  
  start = clock(); // rough but lets see
  printf("median1_sort: %lf  -- %ld ticks\n", 
	 CSPL_Stats_median_sort(dat1, 5),
	 (clock() - start));
  start = clock(); // rough but lets see
  printf("median1_quick: %lf  -- %ld ticks\n", 
	 CSPL_Stats_median_quickselect(dat1, 5), 
	 (clock() - start));
  start = clock(); // rough but lets see
  printf("CSPL_Stats_median_bin: %lf  -- %ld ticks\n", 
	 CSPL_Stats_median_bin(dat1, 5), 
	 (clock() - start));

  
  CSPL_Stats_median_bin(dat1, 5);

  printf("--------------------\n");

  {
    
    double *dat1;
    long c;
    long lens[3]={101, 1000001, 10000001};
    long len;

    for (len=0; len<3; len++) {
      dat1 = (double *)calloc(lens[len], sizeof(double));

      srand(123);
      for (c = 0; c < lens[len]; c++) {
	dat1[c] = rand()%100 + 1;
      }
      /* printf("dat=[ "); */
      /* for(c=0;c<lens[len];c++) */
      /*   printf("%lf, ", dat1[c]); */
      /* printf("]\n"); */
      
      printf("Repeat for %ld random numbers from 0 to 100\n", lens[len]);
      CSPL_Stats_median_bin(dat1, lens[len]);
      start = clock(); // rough but lets see
      printf("CSPL_Stats_median_sort: %lf  -- %ld ticks\n", 
	     CSPL_Stats_median_sort(dat1, lens[len]), 
	     (clock() - start));
      start = clock(); // rough but lets see
      printf("CSPL_Stats_median_quickselect: %lf  -- %ld ticks\n", 
	     CSPL_Stats_median_quickselect(dat1, lens[len]), 
	     (clock() - start));
      start = clock(); // rough but lets see
      printf("CSPL_Stats_median_bin: %lf  -- %ld ticks\n", 
	     CSPL_Stats_median_bin(dat1, lens[len]), 
	     (clock() - start));

      free(dat1);
      printf("--------------------\n");
    }
  }


  return(0);
}






