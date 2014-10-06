
// gcc -I../../CSPL/Sort -L../../ gnomesort.c -lm -Wall -lCSPL -o gnomesort
// install_name_tool -add_rpath ../../ gnomesort


#include <stdio.h>
#include <stdlib.h>

#include "CSPL_Sort.h"

int main(void) {
  double *dat1;
  long i, j;
  long lengths[10] = {10, 50, 100, 200, 300, 400, 500, 700, 800, 1000};
  long nswaps[10];
  char *msg1 = "Better";
  char *msg2 = "Worse";
  char *msg;
    

  for (i=0; i<10;i++) {
    dat1 = (double*)calloc(lengths[i], sizeof(double));
    for (j=0; j<lengths[i]; j++) {
      dat1[j] = ((double)rand())/12.34;
    }
    nswaps[i] = CSPL_Sort_gnomesort(dat1, lengths[i]);
    printf("Random array gnomesorted, %ld elements, %ld swaps\n", 
	   lengths[i], nswaps[i] );
    msg = msg2;
    if (lengths[i]*lengths[i] > nswaps[i])
      msg = msg1;
    printf("\tExpected is n**2 performance: it was %s\n", msg);

    free(dat1);
  }
  




  return(0);
}






