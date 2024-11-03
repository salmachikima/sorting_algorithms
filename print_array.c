#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints array of ints
 *
 * @array: array to be printed
 * @size: the number of elementsin  @array
 */
void print_array(const int *array, size_t size)
{
  size_t s;

  s = 0;
  while (array && s < size)
    {
      if (s > 0)
	printf(", ");
      printf("%d", array[s]);
      ++s;
    }
  printf("\n");
}
