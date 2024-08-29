#include <stdio.h>

void main(){

  int a = 3;
  float f = 2.2;
  char c = 'd';
  int *ptr;
  ptr = &a;
  *ptr = 22;

  printf("hello %d", a);
  printf("hello %d", a);
}
