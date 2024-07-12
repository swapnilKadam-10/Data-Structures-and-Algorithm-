// Linear Sort.


#include <stdio.h>
int search(int arr[], int size, int key)
{
   int flag = 1;
   for (int i = 0; i < size; i++)
   {
      if (arr[i] == key)
         return i;
   }
   return -1;
}
int main()
{
   int size, key;

   printf("\nEnter the size of array:\t");
   scanf("%d", &size);

   int arr[size];

   printf("\nEnter the elements of array:\n");
   for (int i = 0; i < size; i++)
   {
      scanf("%d", &arr[i]);
   }

   printf("\nEnter the no you want to check:\t");
   scanf("%d", &key);

   int result = search(arr, size, key);

   if (result == -1)
      printf("\nThe  number %d  not found \n", key);

   else
      printf("\n The %d   found  at position %d", key, result + 1);
}
