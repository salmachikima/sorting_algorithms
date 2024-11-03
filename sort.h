#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Int in the node
 * @prev: Pointer to the previous element
 * @next: Pointer to the next element
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int get_pivot_index(int *array, size_t size, int first, int last);
void sort_partition(int *array, int size, int first, int last);
void swap(int **array, int first_index, int second_index);
int split(int *arr, int left, int right, size_t size);
void sort_alg(int *arr, int left, int right, size_t size);
#endif
