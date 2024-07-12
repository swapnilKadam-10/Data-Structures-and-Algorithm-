// Insertion Sort

/*
Time Complexity:-
   Best Case: O(n)
   Worst Case: O(n^2)
   Average Case: O(n^2)
*/

#include <stdio.h>
void insertionsort(int arr[], int size)
{
   int i, j, key;

   for (i = 1; i < size; i++)
   {
      key = arr[i];

      for (j = i - 1; j >= 0; j--)
      {
         if (key < arr[j])
         {
            arr[j + 1] = arr[j];
            arr[j] = key;
         }
      }
   }
}
int main()
{
   int size;
   printf("Enter the size of array:\t");
   scanf("%d", &size);

   int arr[size];

   printf("Enter the elements of array:\n");
   for (int i = 0; i < size; i++)
   {
      scanf("%d", &arr[i]);
   }

   printf("\nArray before sorting: \t ");
   for (int i = 0; i < size; i++)
   {
      printf("%d\t", arr[i]);
   }

   insertionsort(arr, size); // function call
   
   printf("\nArray after sorting:\t ");
   for (int i = 0; i < size; i++)
   {
      printf("%d\t", arr[i]);
   }
}
