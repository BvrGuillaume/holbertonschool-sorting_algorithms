#include "sort.h"
/**
* swap - swqp two integers in a array
* @a: first integer
* @b: second integer
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* partition - lomuto partition for quick sort
* @array: array to sort
* @low: starting index of the partition
* @high: ending index of the partition
* @size: size of the array
* Return: pivot index after partitioning
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;
	int j = low;

	for (j = low; j < high; j++)

	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quick_sort_recursive - recursive quick sort implementation
* @array: array to sort
* @low: starting index of the partition
* @high: ending index of the partition
* @size: size of the array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using Quick Sort
* @array: The array to sort
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
