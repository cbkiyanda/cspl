#include <stdio.h>

#include "CSPL_Test.h"
#include "../CSPL/Histogram/CSPL_Histogram.h"


int main(void) {
  {
    // test setting your own bins
    double dat1[15] = {1, 2, 5, 7, 8, 4, 5, 2, 3, 5, 7, 2, 3, 10, 0};
    double edges[5] = {1, 4, 7, 8, 9};
    long ans[4] = {6, 4, 2, 1};
    CSPL_Hist *hist;
    long i, npts;
    hist = CSPL_InitHistogram();
    CSPL_Histogram_set_bins(hist, edges, 4);
    npts = CSPL_Histogram_collect(hist, dat1, 15);
    for (i=0;i<4;i++)
      assert_long_test(hist->count[i], ans[i]);

    assert_long_test(hist->underflow, 1);
    assert_long_test(hist->overflow, 1);
    assert_long_test(npts, 15);
    CSPL_Free_Hist(hist);
  }
  {
    // test setting linear auto bins
    double dat1[15] = {1, 2, 5, 7, 8, 4, 5, 2, 3, 5, 7, 2, 3, 10, 0};
    long ans[4] = {4, 3, 3, 3};
    CSPL_Hist *hist;
    long i, npts;
    hist = CSPL_InitHistogram();
    CSPL_Histogram_set_uniform(hist, 1, 9, 4);
    npts = CSPL_Histogram_collect(hist, dat1, 15);
    for (i=0;i<4;i++)
      assert_long_test(hist->count[i], ans[i]);

    assert_long_test(hist->underflow, 1);
    assert_long_test(hist->overflow, 1);
    assert_long_test(npts, 15);
    CSPL_Free_Hist(hist);
  }
  return(0);
}

