#include <stdio.h>

int size_double(void) {
  return sizeof(double);
}

int
main (void)
{
  printf("size = %d\n", size_double());
  return 0;
}
