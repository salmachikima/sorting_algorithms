#include "sort.h"

/**
  * quick_sort - the quicksort algorithm
  * @array: sorted array
  * @size: the array's size
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sort_alg(array, 0, size - 1, size);
}

/**
  * sort_alg - recursive sorting
  * @size: full array size
  * @arr: array
  * @right: rightmost index
  * @left: leftmost index
  */

void sort_alg(int *arr, int left, int right, size_t size)
{
	int p;/*pivotement*/

	if (left < right)
	{
		p = split(arr, left, right, size);
		sort_alg(arr, left, p - 1, size);
		sort_alg(arr, p + 1, right, size);
	}
}

/**
  * split - split array
  * @left: leftmost index
  * @right: rightmost index
  * @arr: array
  * @size: full size of array
  * Return: pivot index
  */
int split(int *arr, int left, int right, size_t size)
{
	int r;
	int s;
	int p; 
	int t;

	p = arr[right];
	r = left;

	for (s = left; s < right; s++)
	{
		if (arr[s] < p)
		{
			if (r != s)
			{
				t = arr[s];
				arr[s] = arr[r];
				arr[r] = t;
				print_array(arr, size);
			}
			r++;
		}
	}
	if (arr[r] != arr[right])
	{
		t = arr[r];
		arr[r] = arr[right];
		arr[right] = t;
		print_array(arr, size);
	}

	return (r);
}
