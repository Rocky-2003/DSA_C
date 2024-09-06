#include <stdio.h>
int c(int n){
   int  y = 1;
  static int x = 20;
  if(n>1){
    x = x + 5;
    y++;
    return y*c(n - 2) + x;
  }
  return 1;
}

int main(){
  int resutl = c(8);
  
  printf("%d",resutl);
}