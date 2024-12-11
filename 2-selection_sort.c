#include "sort.h"

/**
* swap - swaps two elements in an array
* @a: first element
* @b: second element
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* selection_sort - sorts an array using the Selection sort algorithm
* @array: pointer to the array
* @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;


		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}


		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);

			print_array(array, size);
		}
	}
}
