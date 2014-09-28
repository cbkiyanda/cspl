
#include "CSPL_Sort.h"

// from stdlib example docs
int CSPL_Sort_comparedoubles(const void *a, const void *b)
{
  const double *da = (const double *) a;
  const double *db = (const double *) b;

  return (*da > *db) - (*da < *db);
}


