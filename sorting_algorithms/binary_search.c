// Binary search

/*
 Time Complexity:-
  Best Case: O(1)
  Worst Case: O(log n)
  Average Case: O(logn)
*/

#include <stdio.h>
void bubblesort(int arr[], int size)
{
  int i, j, temp;
  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
int search(int arr[], int size, int key)
{
  int low, high, mid;
  low = 0;
  high = size - 1;
  while (low <= high)
  {
    mid = (low + high) / 2; // Calculating mid position.

    if (key < arr[mid])
      high = mid - 1;
    else if (key > arr[mid])
      low = mid + 1;
    else if (key == arr[mid])
      return mid;
  }
  return -1;
}
int main()
{
  int size, key;

  printf("Enter the size of array:\t");
  scanf("%d", &size);

  int arr[size];

  printf("\nEnter the elements of array:\n");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("\nArray Elements are:\t");
  for (int i = 0; i < size; i++)
  {
    printf("%d\t", arr[i]);
  }

  bubblesort(arr, size); // to sort array

  printf("\nArray after sorting:\t");
  for (int i = 0; i < size; i++)
  {
    printf("%d\t", arr[i]);
  }

  printf("\nEnter the no you want to check:\t");
  scanf("%d", &key); // Taking the number from user to search in the array.

  int result = search(arr, size, key);

  if (result == -1)
    printf("\nThe  number %d  not found.", key);

  else
    printf("\nThe %d found  at index %d.", key, result);

  return 0;
}
