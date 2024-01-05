#include <stdio.h>

int main(void) {
  int n = 50;

  printf("The integer is: %i \n", n);
  printf("The addr of The integer is: %p \n", &n);
  printf("The addr of The next integer is: %p \n", &n + 1);

  int *point = &n;
  printf("The addr of The integer is: %p \n", point);
  printf("The value of The integer is: %i \n", *point);
  printf("The value of The next integer is: %i \n", *(point+1));
  printf("The value of The next integer is: %i \n", *(point+2));
  

  // print

  printf("size of int: %lu \n", sizeof(int));
  
  char *ptr_char = (char *)point;
  printf("size of int: %p \n", ptr_char+1);
  printf("int is: %c \n", *(ptr_char+1));


  //
  printf("peeking and poking\n");
  
  char *p,a;

  p = (char *)0x7fff09677cfc;
  a = *p;

  printf("int is: %i \n", a);
  
}
