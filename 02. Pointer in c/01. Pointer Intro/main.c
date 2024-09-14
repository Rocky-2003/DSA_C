#include <stdio.h>



int main(){
  int a = 34;
  int *b;
  b = &a;
  printf("%d\n", a);
  a = 23;
  printf("%d\n", *b);
  printf("%d\n", a);



  
}