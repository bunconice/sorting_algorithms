#include "sort.h"

/**
 * bubble_sort - sort array of integers
 * @array: pointer to first element of array of integers
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int swapped, temp = 0;

	if (size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
