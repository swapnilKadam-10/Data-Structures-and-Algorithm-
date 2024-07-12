// Selection sort

/*
 Time Complexity:-
  Best Case : O(n^2)
  Worst Case : O(n^2)
  Average Case : O(n^2)
*/

#include <stdio.h>
void selection_sort(int arr[], int size)
{
    int temp, swap;

    for (int i = 0; i < size; i++)
    {
        temp = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[temp])
            {
                temp = j;
            }
        }
        swap = arr[temp];
        arr[temp] = arr[i];
        arr[i] = swap;
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

    selection_sort(arr, size); // function call

    printf("\nArray after sorting:\t");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}