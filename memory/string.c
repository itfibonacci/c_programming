#include <stdio.h>

int main(void) {
  
  char *x = "Hello how is it going?";
  
  printf("print the string: %p\n", x);
  printf("print the string: %p\n", x+1);
  printf("print the string: %s\n", x+1);
  
  return 0;
}