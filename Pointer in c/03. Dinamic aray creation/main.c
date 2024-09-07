#include <stdio.h>
#include <stdlib.h>


void main(){

  int *arr;
  int n,i;
  printf("Enter the no. of Elements\n");
  scanf("%d", &n);
  arr = (int *)malloc(sizeof(int) * n);

  printf("Memeory Address\n");
  for ( i = 0; i < n; i++){
    printf("%d\n", arr[i]);
  }


 ;
  printf("Enter Elements\n");
  for ( i = 0; i < n; i++){
    // arr[i] = i;
    scanf("%d", &arr[i]);
  }
  printf("Elments\n");
  for (i = 0; i < n; i++)
  {

    printf("Hello %d\n", arr[i]);
  }

  
    
}