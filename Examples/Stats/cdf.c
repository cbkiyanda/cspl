
// gcc -I../../CSPL/Array -I../../CSPL/Stats -L../../ cdf.c -lm -Wall -lCSPL -o cdf
// install_name_tool -add_rpath ../../ cdf

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CSPL_Stats.h"
#include "CSPL_Array.h"


int main(void) {
  FILE *fp;
  const char *filename = "goog.csv";
  long lines=0;
  char ch;
  double *close, *close_cdf, *cdf67l, *cdf67h, *cdf99l, *cdf99h;
  long i;
  char tmps[256];

  printf("1) read in some data of google stock prices (goog.csv)\n");
  printf("2) Compute the CDF\n");
  printf("3) Compute the 67th and 99th confidence bands\n");
  printf("4) Dump out to text file (goog_cdf.csv)\n");
  printf("5) (Opt) Plot data using plot_goog_cdf.py (matplotlib)\n");

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "%s -- %s\n", filename, strerror(ENOENT));
    exit(ENOENT);
  }

  // get the number of lines in the file
  while(!feof(fp))
    {
      ch = fgetc(fp);
      if(ch == '\n')
	{
	  lines++;
	}
    }
  // go back to the start of the file
  fseek(fp, 0, SEEK_SET);

  // 1111111111111111111111111
  // allocate memory to hold the close price
  close     = (double *)calloc(lines, sizeof(double));
  close_cdf = (double *)calloc(lines, sizeof(double));
  cdf67l = (double *)calloc(lines, sizeof(double));
  cdf67h = (double *)calloc(lines, sizeof(double));
  cdf99l = (double *)calloc(lines, sizeof(double));
  cdf99h = (double *)calloc(lines, sizeof(double));

  for (i=0;i<lines-1;i++) {
    fgets(tmps, 256, fp);
    close[i] = atof(tmps);
  }

  // 22222222222222222222222222
  CSPL_Stats_tCDF(close, close_cdf, lines);
  // 33333333333333333333333333
  CSPL_Stats_tCDF_confidence_bands(close_cdf, cdf67l, cdf67h, 1.0-0.67, lines);
  CSPL_Stats_tCDF_confidence_bands(close_cdf, cdf99l, cdf99h, .01, lines);
  // 44444444444444444444444444
  CSPL_Array_filedump1d("goog_cdf.csv", lines, 6, close, close_cdf, 
			cdf67l, cdf67h, 
			cdf99l, cdf99h);

  fclose(fp);
  free(close);
  free(close_cdf);
  free(cdf67l);
  free(cdf67h);
  free(cdf99l);
  free(cdf99h);
}




