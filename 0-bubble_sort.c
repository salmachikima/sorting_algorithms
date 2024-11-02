#include "sort.h"

/**
 * bubble_sort - function that sort an array of ints
 * using the Bubble sort algorithm
 *
 * @array: The array to be sorted.
 * @size: size of @array.
 *
 **/
void bubble_sort(int *array, size_t size)
{
	int p = 0;
	int i = 0;
	int passes_required = 0;
	int last_index = 0;
	int t = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	passes_required = size - 1;
	for (p = 0; p < passes_required; p++)
	{
		last_index = size - p - 1;
		for (i = 0; i < last_index; i++)
		{
			if (array[i] > array[i + 1])
			{
				t = array[i];
				array[i] = array[i + 1];
				array[i + 1] = t;
				print_array(array, size);
			}
		}
	}
}
