#include "sort.h"

/**
* bubble_sort - function that sorts an array of integers
* @array: after each time you swap two elements
* @size: size of the array
* Description: function that sorts an array of integers in ascending order
* Return: print the array
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
