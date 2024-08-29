#include <stdio.h>


int main(){

int sum(int n) { 
  if(n==0)
    return 0;

  return n + sum(n - 1);
}

int val = sum(5);

printf("%d", val);
}