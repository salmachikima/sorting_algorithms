#include "sort.h"

/**
 * selection_sort - function that sorts an array of ints using
 * the Selection sort algorithm in ascendance
 * @array: pointer to the array
 * @size: the size of the array
 **/

void selection_sort(int *array, size_t size)
{
	int a;
	int f;
	size_t i, j, n, k;

	if (array)
	{
		for (i = 0; i < size; i++)
		{
			a = array[i];
			f = 0;
			for (j = i; j < size ; j++)
			{
				if (array[j] < a)
				{
					k = j;
					a = array[j];
					f = 1;
				}
			}
			if (f == 1)
			{
				n = array[i];
				array[i] = array[k];
				array[k] = n;
				print_array(array, size);
			}
		}
	}
}
