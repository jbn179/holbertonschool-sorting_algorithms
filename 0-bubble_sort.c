#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order using
*               the bubble sort algorithm.
* @array: A pointer to the array of integers to be sorted.
* @size: size of the array
* Description: This function sorts an array of integers using the Bubble
 *              Sort algorithm. It iterates over the array multiple times,
 *              repeatedly swapping adjacent elements if they are in the wrong
 *              order. After each swap, the array is printed.
 *              The algorithm stops early if no swaps are made in a pass,
 *              indicating that the array is already sorted
* Return: None. The function sorts the array in place.
*/

void bubble_sort(int *array, size_t size)
{
size_t i, j;
	int temp;

	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/*Swap the elements*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/*Print the array after each swap*/
				for (size_t k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
						printf(", ");
				}
				printf("\n");

				swapped = 1;
			}
		}
		/*If no two elements were swapped by inner loop, then the array is sorted*/
		if (!swapped)
			break;
	}


}
