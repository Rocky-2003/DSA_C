#include <stdio.h>
#include <stdlib.h>



int main(){
  int *arr;
  int n1,i,n2;

  printf("Enter no. of elements\n");
  scanf("%d", &n1);

  arr = (int *)calloc(n1, sizeof(int));

  printf("Default value at memory block provided by calloc\n");
  for (i = 0; i < n1; i++){
    printf("%d\n",arr[i]);
  }

  printf("Enter elements in memory\n");
  for (i = 0; i < n1; i++){
    scanf("%d\n", &arr[i]);
  }

  // printf("Elements you Entered is:\n");
  // for (i = 0; i < n1; i++){
  //   printf("%d\n", arr[i]);

  // }

  printf("Enter new Memory you want:");
  scanf("%d", &n2);

  arr = realloc(arr, (n1 + n2));

  printf("New memory and you elements:\n");
  for (i = 0; i < n2; i++){
    printf("%d\n", arr[i]);
  }
}