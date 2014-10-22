
#include <math.h>


#include <stdio.h>

#include "CSPL_MonteCarlo.h" 
#include "../Stats/CSPL_Stats.h" 
 
/** Compute the jackknife parameters from the struct
 *
 * @param[inout] jn CSPL_Jackknife pointer populated with data
 */
void CSPL_Compute_Jackknife(CSPL_Jackknife *jn) {
  jn->mean = CSPL_Stats_mean(jn->data, jn->nreps);
  jn->var  = CSPL_Stats_variance(jn->data, jn->nreps);
  jn->std  = sqrt(jn->var);
  jn->bias = jn->nreps*jn->centerval-(jn->nreps-1)*jn->mean;
}

