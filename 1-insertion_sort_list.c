#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * using insertion sort methode
 * @list: pointer to the head of the list
 * Return: nothing
 **/

void insertion_sort_list(listint_t **list)
{
	int f; /*which means flag but i decided to call it f cs im lazy*/
	listint_t *head_tmp1, *head_tmp2, *aux1, *aux2;

	if (list)
	{
		head_tmp1 = *list;
		head_tmp2 = *list;
		while (list && head_tmp1->next)
		{
			if (head_tmp1->next)
			{
				f = 0;
				head_tmp2 = head_tmp1;
				while (head_tmp2 && head_tmp2->n > head_tmp2->next->n)
				{
					aux1 = head_tmp2;
					aux2 = head_tmp2->next;
					aux1->next = aux2->next;
					if (aux2->next)
						aux2->next->prev = aux1;
					if (aux2)
					{
						aux2->prev = aux1->prev;
						aux2->next = aux1;
					}
					if (aux1)
						aux1->prev = aux2;
					if (aux2->prev)
						aux2->prev->next = aux2;
					head_tmp2 = aux2->prev;
					if (!aux2->prev)
						*list = aux2;
					print_list(*list);
					f = 1;
				}
			}
			if (f == 0)
				head_tmp1 = head_tmp1->next;
		}
	}
}
