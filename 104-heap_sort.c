#include "sort.h"

/**
 * check_tree - swiftdown check
 * @array: pointer to array
 * @size_init: original size
 * @size: pointer size
 * @i: index aka tree root
 *
**/

void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int s;
	int branch1;
	int branch2;
	size_t brat1;
	size_t brat2;

	brat1 = i * 2 + 1;
	brat2 = brat1 + 1;
	branch1 = array[brat1];
	branch2 = array[brat2];
	if (((brat1 < size) && (brat2 < size) &&
		(branch1 >= branch2 && branch1 > array[i]))
		|| ((brat1 == size - 1) && branch1 > array[i]))
	{
		s = array[i];
		array[i] = branch1;
		array[brat1] = s;
		print_array(array, size_init);
	}
	else if ((brat1 < size) && (brat2 < size) &&
		(branch2 > branch1 && branch2 > array[i]))
	{
		s = array[i];
		array[i] = branch2;
		array[brat2] = s;
		print_array(array, size_init);
	}
	if (brat1 < size - 1)
		check_tree(array, size_init, size, brat1);
	if (brat2 < size - 1)
		check_tree(array, size_init, size, brat2);
}
/**
 * heap_sort - sorts an array of integers using the Heap
 * sort algorithm
 * @size: pointer size
 * @array: pointer to array
**/
void heap_sort(int *array, size_t size)
{
	size_t r;
	size_t size_init = size;
	int s;

	if (!array)
		return;
	for (r = 0; r < size / 2 ; r++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - r);
	}
	for (r = 0; r < size_init - 1; r++)
	{
		s = array[0];
		array[0] = array[size - 1 - r];
		array[size - 1 - r] = s;
		print_array(array, size_init);
		check_tree(array, size_init, size - r - 1, 0);
	}

}
