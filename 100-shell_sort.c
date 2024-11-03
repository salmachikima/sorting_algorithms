#include "sort.h"

/**
  * shell_sort - shell sort using knuth sequence
  * @array: sorted array
  * @size: the size
  */

void shell_sort(int *array, size_t size)
{
	int t;
	size_t k;
	size_t r, s;

	k = 1;
	while (k < size)
		k = (k * 3) + 1;
	k = (k - 1) / 3;
	while (k > 0)
	{
		for (r = k; r < size; r++)
		{
			t = array[r];
			for (s = r; s >= k && array[s - k] > t; s -= k)
				array[s] = array[s - k];
			array[s] = t;
		}
		k = (k - 1) / 3;
		print_array(array, size);
	}
}
