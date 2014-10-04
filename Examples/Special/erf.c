
// gcc -I../../CSPL/Special -I../../CSPL/Array -L../../ erf.c -lm -Wall -lCSPL -o erf 
// install_name_tool -add_rpath ../../ erf


#include <stdio.h>

#include "CSPL_Array.h"
#include "CSPL_Special.h"

int main(void) {
  long i, ind;
  double val[101];
  double x[101];
  const char * filename = "erf_data.txt";
  printf("CSPL_Special_Erf1(0.0) = %lf\n",CSPL_Special_Erf1(0.0));
  printf("CSPL_Special_Erf1(-1.0) = %lf\n",CSPL_Special_Erf1(-1.0));
  printf("CSPL_Special_Erf1(1.0) = %lf\n",CSPL_Special_Erf1(1.0));
  printf("CSPL_Special_Erf1(3.0) = %lf\n",CSPL_Special_Erf1(3.0));
  printf("CSPL_Special_Erf1(-3.0) = %lf\n",CSPL_Special_Erf1(-3.0));
  
  ind=0;
  for (i=-50;i<51;i++) { 
    x[ind] = (double)i/(50./3.); 
    val[ind] = CSPL_Special_Erf1(x[ind]);
    ind++;
   } 

  
   printf("\nDumping Answer and input file named %s\n", filename); 

   CSPL_Array_filedump1d(filename, 101, 2, x, val); 
   //CSPL_Array_filedump1d(filename, 101, 1, x); 

  return(0);
}






