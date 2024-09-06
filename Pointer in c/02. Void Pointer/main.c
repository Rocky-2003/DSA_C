#include <stdio.h>

int main(){

  int a = 33.3;
  void *pointer = &a;
  printf("%d\n", *(int*)pointer);
  printf("%d\n", *(char*)pointer);
  printf("%d\n", *(float*)pointer);
}