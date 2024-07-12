// Merge sort.

/*
 Time Complexity:-
  Best Case : O(n log n)
  Worst Case : O(n log n)
  Average Case : O(n log n)
*/


#include <stdio.h>
void sort(int arr[], int first, int mid, int last)
{
  int i, j, k;

  int size = last - first + 1;

  int temp[size];

  i = first;
  j = mid + 1;
  k = 0;

  while (i <= mid && j <= last)
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
    }
  }
  while (i <= mid)
  {
    temp[k++] = arr[i++];
  }
  while (j <= last)
  {
    temp[k++] = arr[j++];
  }

  for (i = 0, j = first; i < size; i++, j++)
  {
    arr[j] = temp[i];
  }
}
void divide(int arr[], int first, int last)
{
  if (first >= last)
  {
    return;
  }

  if (first != last)
  {
    int mid = first + (last - first) / 2;

    divide(arr, first, mid);
    divide(arr, mid + 1, last);
    sort(arr, first, mid, last);
  }
}
int main()
{
  int size;
   printf("Enter the size of array:\t");
   scanf("%d", &size);

   int arr[size];

   printf("\nEnter the elements of array:\n");
   for (int i = 0; i < size; i++)
   {
      scanf("%d", &arr[i]);
   }

   printf("\nArray elements are:\t");
   for (int i = 0; i < size; i++)
   {
      printf("%d\t", arr[i]);
   }

   divide(arr, 0, size - 1); // function call

   printf("\nArray after sorting:\t");
   for (int i = 0; i < size; i++)
   {
      printf("%d\t", arr[i]);
   }

   return 0;
}
