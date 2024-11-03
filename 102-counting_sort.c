#include "sort.h"
/**
 * counting_sort - sorts an array of ints
 * using the Counting sort algorithm
 * @array: pointer to array
 * @size: array size
 **/

void counting_sort(int *array, size_t size)
{
	int s, r;
	int *count_array, *a;
	size_t d;

	if (!array || size < 2)
		return;
	s = array[0];
	for (d = 0; d < size; d++)
	{
		if (array[d] > s)
			s = array[d];
	}
	count_array = calloc((s + 1), sizeof(int));
	for (d = 0; d < size; d++)
	{
		count_array[array[d]]++;
	}
	for (r = 1; r < s; r++)
	{
		count_array[r + 1] += count_array[r];
	}
	print_array(count_array, s + 1);
	a = malloc(sizeof(int) * size);
	for (d = 0; d < size; d++)
	{
		count_array[array[d]]--;
		a[count_array[array[d]]] = array[d];
	}
	for (d = 0; d < size; d++)
	{
		array[d] = a[d];
	}
	free(a);
	free(count_array);
}

