#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order using
*               the Bubble Sort algorithm.
* @array: A pointer to the array of integers to be sorted.
* @size: The size of the array.
*
* Description: This function sorts an array of integers in ascending order
*              using the Bubble Sort algorithm. It iterates over the array
*              multiple times, comparing adjacent elements and prints the
*              array after each comparison. This version does not use the
*              swapped flag to stop early.
*
* Return: None. The function sorts the array in place.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap the elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Print the array after each swap */
				for (size_t k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
						printf(", ");
				}
				printf("\n");
			}
		}
	}
}
