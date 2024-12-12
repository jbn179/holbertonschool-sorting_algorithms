#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 * Description: function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	/* Check if the list is empty or contains only one element */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = *list;
	current = sorted->next;

	/* Iterate through the unsorted part of the list */
	while (current != NULL)
	{
		temp = current->next;

		/* Move current element to its correct position in the sorted part */
		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* Adjust next pointers */
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;

			/* Move current node one position back */
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			/* Update list head if necessary */
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;

			/* Print the list after each swap */
			print_list(*list);
		}
		/* Move to the next unsorted element */
		current = temp;
	}
}
