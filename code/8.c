#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  printf("Prerit || BCA-2A");
  int arr[100], n, x, result;
  printf("\nEnter the size of the array: ");
  scanf("%d", &n);
  printf("Enter the elements of the sorted array: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  printf("Enter the element to search: ");
  scanf("%d", &x);
  result = binarySearch(arr, 0, n - 1, x);
  if (result == -1)
    printf("Element is not present in array");
  else
    printf("Element is present at index %d", result);
  return 0;
}