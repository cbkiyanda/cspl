

/** Compute the factorial of an integer, TODO can we do long long?
 * @param[in] n Value to compute the factorial of
 * @return The factorial of the input (n!)
 */
unsigned long CSPL_Special_factorial(unsigned long n) {
  unsigned long ans=1;
  unsigned long i;
  
  for (i=1; i<=n; i++) {
    ans *= i;
  }
  return(ans);
}



