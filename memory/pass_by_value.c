#include <stdio.h>

int pass_by_value(int n)
{
  int *pn = &n;
  printf("%p\n", pn);
}

int pass_by_value2(int *n)
{
  *n = 40;
  //printf("%p\n", nn);
}

int main(void) {
  int n,m, *pn, *pm;

  n = 50;

  pn = &n;

  printf("The address of n is: %p\n", pn);

  m = *pn;

  printf("The value of m is: %i\n", m);
  printf("The address of m is: %p\n", &m);

  

  pass_by_value(n);
  pass_by_value2(&n);
  
  printf("n is: %i\n", n);
  
  return 0;
}