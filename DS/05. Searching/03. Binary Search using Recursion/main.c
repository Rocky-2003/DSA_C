#include <stdio.h>

int binarySerach(int arr[], int left, int right, int target)
{
  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    // Check if the target is present at mid
    if (arr[mid] == target)
      return mid;

    // If target is greater, ignore the left half
    if (arr[mid] < target)
      return binarySerach(arr, mid + 1, right, target);
    // If target is smaller, ignore the right half
    else
      return binarySerach(arr, left, mid - 1, target);
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int startIndex = 0;
  int lastIndex = 10;
  int element;
  // printf("%d", 9 / 2);
  printf("Enter element: ");
  scanf("%d", &element);
  int result = binarySerach(arr, startIndex, lastIndex, element);
  if (result == -1)
  {
    printf("Element not Found\n");
  }
  else
  {

    printf("Element found at : %d\n", result);
  }
}