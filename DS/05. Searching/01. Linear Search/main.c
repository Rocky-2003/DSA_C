#include <stdio.h>

int linearSearch(int arr[], int lastIndex, int element)
{
  for (int i = 0; i <= lastIndex; i++)
  {
    if (arr[i] == element)
    {
      //? Swap technique
      // int n = arr[i];
      // arr[i] = arr[i - 1];
      // arr[i - 1] = n;

      //? Move to first
      int n = arr[i];
      arr[i] = arr[0];
      arr[0] = n;
      return i;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {10, 9, 7, 3, 5, 8, 13, 16, 18, 19};
  int lastIndex = 9;
  printf("Enter Element: ");
  int element;
  scanf("%d", &element);
  int result = linearSearch(arr, lastIndex, element);
  if (result >= 0)
  {
    printf("Element found at %d index\n", result);
  }
  else
  {
    printf("Element not found\n");
  }

  for (int i = 0; i <= lastIndex; i++)
    printf("%d ", arr[i]);
}