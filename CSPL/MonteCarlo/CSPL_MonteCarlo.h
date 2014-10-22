#ifndef CSPL_BOOTSTRAP_H
#define CSPL_BOOTSTRAP_H

typedef struct CSPL_Jackknife {
  double *data;     /// the data from the jackknife
  double centerval; /// center value from the overall calculation
  long nreps;       /// the number of repititions
  long index;       /// the current index in the repitions
  double mean;      /// the jackknife mean
  double var;       /// the jackknife variance
  double std;       /// the jackknife standard deviation
  double bias;      /// the jackknife bias
} CSPL_Jackknife;

void CSPL_Compute_Jackknife(CSPL_Jackknife *jn);


#endif /* CSPL_BOOTSTRAP_H */

