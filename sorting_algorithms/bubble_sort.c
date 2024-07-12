// Bubble sort.

/*
 Time Complexity :
  Best Case: O(n)
  Average Case: O(n^2)
  Worst Case: O(n^2)
*/

#include <stdio.h>
void bubblesort(int arr[], int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
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
int main()
{
  int size;
  printf("Enter the number of Elements in the array: ");
  scanf("%d", &size);

  int arr[size];

  printf("\nEnter the Element to add to the array:\n ");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("\nArray before sorting: \t ");
  for (int i = 0; i < size; i++)
  {
    printf("%d\t", arr[i]);
  }

  bubblesort(arr, size); // function Call

  printf("\nArray after sorting:\t ");
  for (int i = 0; i < size; i++)
  {
    printf("%d\t", arr[i]);
  }
}
