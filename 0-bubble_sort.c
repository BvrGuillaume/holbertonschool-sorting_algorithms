#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* bubble_sort - Sort an array of integers in ascending order using Bubble sort
* @array: Pointer to the array of integers
* @size: The size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Print the array after each swap */
				print_array(array, size);

				swapped = 1;
			}
		}

		/* If no two elements were swapped, break */
		if (!swapped)
			break;
	}
}
