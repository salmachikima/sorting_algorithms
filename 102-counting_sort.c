#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of ints
 * using the Counting sort algorithm in ascendance
 * @array: sorted array
 * @size: array size
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int *arrayc;
	int g;
	size_t s;
	size_t r;
	size_t arraysize;

	if (array == NULL || size <= 1)
		return;
	arraysize = array[0];
	for (s = 0; array[s]; s++)
	{
		if (array[s] > (int)arraysize)
			arraysize = array[s];
	}

	arraysize += 1;

	arrayc = malloc(arraysize * sizeof(int *));
	if (arrayc == NULL)
		return;

	for (s = 0; s < arraysize; s++)
		arrayc[s] = 0;

	for (s = 0; s < size; s++)
		arrayc[array[s]] += 1;

	for (s = 0; s <= arraysize; s++)
		arrayc[s] += arrayc[s - 1];

	print_array(arrayc, arraysize);

	for (s = 1, r = 0; s <= arraysize; s++)
		if (arrayc[s] != arrayc[s - 1])
		{
			for (g = 0; g < arrayc[s] - arrayc[s - 1]; g++)
				array[r++] = s;
		}
	free(arrayc);
}
