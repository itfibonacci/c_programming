#include <stdio.h>

int* passbyvalue(int a) {
  return &a;
}

int main() {
  printf("%p", passbyvalue(123));
  return 0;
}
