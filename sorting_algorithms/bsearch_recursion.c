// Binary search using recursion.

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

int binarysearch(int arr[], int key, int low, int high)
{
	while (low < high)
	{
		int mid = (high + low) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		else
		{
			if (arr[mid] < key)
			{
				return (binarysearch(arr, key, mid + 1, high));
			}
			else
			{
				return (binarysearch(arr, key, low, mid - 1));
			}
		}
	}
	return -1;
}
int main()
{
	int size, key, result = -1;

	printf("\nEnter the no of elements:\t");
	scanf("%d", &size);

	int arr[size];

	printf("\nEnter the values:\n");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	bubblesort(arr, size); // to sort array elements

	printf("\nEnter the key to search:\t");
	scanf("%d", &key);

	result = binarysearch(arr, key, 0, size);

	if (result == -1)
	{
		printf("\nThe  number %d  not found.", key);
	}
	else
	{
		printf("\nThe %d found  at index %d.", key, result);
	}
	return 0;
}