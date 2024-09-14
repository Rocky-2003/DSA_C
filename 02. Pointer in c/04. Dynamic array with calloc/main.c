#include <stdio.h>
#include <stdlib.h>


int main(){

  int *arr;
  int n,i;
  // Enter Elements
  printf("Enter Number of Elements\n");
  scanf("%d",&n);
  // Allocating memory
  arr = (int *)calloc(n, sizeof(int));

  // Elements filled by calloc
  for (i = 0; i < n; i++){
    printf("%d\n",arr[i]);
  }
  // Enter Elements
  printf("Enter Elements\n");
  for (i = 0; i < n; i++){
    scanf("%d\n", &arr[i]);
  }

  // Print Elements of arr
  printf("Elements you entered");
  for (i = 0; i < n;i++){
    
    printf("\n%d", arr[i]);
  }

    return 0;
}