// Quick sort , last pivot .

/*
 Time Complexity:-
  Best Case : O(n log n)
  Worst Case : O(n^2)
  Average Case : O(n log n)
*/


#include <stdio.h>
void sort(int arr[], int first, int last)
{

  int i, j, temp, pivot;

  pivot = last; // setting pivot element to last position.
  i = first;
  j = last;

  while (i < j)
  {
    while (arr[i] <= arr[pivot] && i < last)
      i++;

    while (arr[j] > arr[pivot])
      j--;

    if (i < j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    sort(arr, first, j - 1);
    sort(arr, j + 1, last);
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

   quickSort(arr, 0, size); // function call

   printf("\nArray after sorting:\t");
   for (int i = 0; i < size; i++)
   {
      printf("%d\t", arr[i]);
   }

   return 0;
}