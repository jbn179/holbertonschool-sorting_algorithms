# 📚 Holberton School Sorting Algorithms

![Python](https://img.shields.io/badge/Python-3.8%2B-blue.svg)
![Progress](https://img.shields.io/badge/Progress-Intermediate-yellow.svg)

## 📖 Description
This repository contains C programs that demonstrate various sorting algorithms. The goal is to provide a comprehensive understanding of how different sorting algorithms work, their implementation, and their performance characteristics. Each script is designed to be simple and easy to understand, making them ideal for learners who are looking to deepen their knowledge of sorting algorithms.

The algorithms cover a range of topics, including:
- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort

## 📂 Contents
- **0-bubble_sort.c**: Implements the Bubble Sort algorithm.
- **1-insertion_sort_list.c**: Implements the Insertion Sort algorithm for doubly linked lists.
- **2-selection_sort.c**: Implements the Selection Sort algorithm.
- **3-quick_sort.c**: Implements the Quick Sort algorithm.

## 🚀 Getting Started
1. Clone the repository to access the materials:
   ```bash
   git clone https://github.com/username/holbertonschool-sorting_algorithms.git
   ```
2. Navigate to the directory:
   ```bash
   cd holbertonschool-sorting_algorithms
   ```
3. Compile and run the C programs:
   ```bash
   gcc -Wall -Wextra -Werror -pedantic 0-bubble_sort.c -o bubble_sort
   ./bubble_sort
   ```

## 🛠️ Requirements
• GCC compiler for C programs  
• Linux or macOS environment (recommended)

## Examples

### 0-bubble_sort.c
Implements the Bubble Sort algorithm:
```c
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
```

### 1-insertion_sort_list.c
Implements the Insertion Sort algorithm for doubly linked lists:
```c
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using the Insertion Sort algorithm.
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        next = current->next;
        temp = current->prev;
        while (temp != NULL && temp->n > current->n)
        {
            temp->next = current->next;
            if (current->next != NULL)
                current->next->prev = temp;
            current->prev = temp->prev;
            current->next = temp;
            if (temp->prev != NULL)
                temp->prev->next = current;
            else
                *list = current;
            temp->prev = current;
            temp = current->prev;
        }
        current = next;
    }
}
```

### 2-selection_sort.c
Implements the Selection Sort algorithm:
```c
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the Selection Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;
    int temp;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
        }
    }
}
```

### 3-quick_sort.c
Implements the Quick Sort algorithm:
```c
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}

/**
 * quick_sort_recursive - Recursively sorts an array using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @low: The starting index.
 * @high: The ending index.
 */
void quick_sort_recursive(int *array, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high);
        quick_sort_recursive(array, low, pivot - 1);
        quick_sort_recursive(array, pivot + 1, high);
    }
}

/**
 * partition - Partitions an array for the Quick Sort algorithm.
 * @array: The array to be partitioned.
 * @low: The starting index.
 * @high: The ending index.
 * Return: The partition index.
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}
```

## License
![License](https://img.shields.io/badge/License-MIT-green.svg)  
This project is under the MIT License.

## Author
Benjamin Ristord - [@jbn179](https://github.com/jbn179)