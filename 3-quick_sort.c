#include "sort.h"

/**
* swap - Swaps two integers
* @a: Pointer to first integer
* @b: Pointer to second integer
* Description: Exchanges the values of two integers using a temporary variable
* Return: void
*/

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* lomuto_partition - Implements Lomuto partition scheme for Quick sort
* @array: Array to be partitioned
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Total size of the array
* Description: Selects last element as pivot and partitions array around it
* Return: Index of the pivot after partitioning
*/

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	int j;

	for (j = low; j <= high - 1; j++)
	{
		/* If current element is smaller than pivot */
		if (array[j] < pivot)
		{
			i++;

			/* Swap elements if needed and print the array */
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	/* Place pivot in its correct position */
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quick_sort_recursive - Recursive implementation of Quick sort algorithm
* @array: Array to be sorted
* @low: Starting index of the array or subarray
* @high: Ending index of the array or subarray
* @size: Total size of the original array
* Description: Recursively partitions and sorts array using Quick sort method
* Return: void
*/

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		/* Partition the array */
		int partition_index = lomuto_partition(array, low, high, size);

		/* Recursively sort left and right subarrays */
		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
* quick_sort - Main function to initiate Quick sort
* @array: Array to be sorted
* @size: Number of elements in the array
* Description: Checks array validity and starts recursive Quick sort process
* Return: void
*/

void quick_sort(int *array, size_t size)
{
	/* Check if array is valid and has more than one element */
	if (array == NULL || size < 2)
		return;

	/* Start recursive Quick Sort */
	quick_sort_recursive(array, 0, size - 1, size);
}
