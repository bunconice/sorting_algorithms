#include "sort.h"

/**
 * swap - Swaps two elements in an array and prints the array.
 * @array: The array.
 * @i: Index of the first element.
 * @j: Index of the second element.
 * @size: size of array
 */
void swap(int *array, int i, int j, size_t size)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme.
 * @array: The array to be sorted.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
				swap(array, i, j, size);
		}
	}
	if (i + 1 != high)
		swap(array, i + 1, high, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quick sort.
 * @array: The array to be sorted.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm with Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
