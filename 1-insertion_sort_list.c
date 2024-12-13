#include "sort.h"
/**
* insertion_sort_list - Sort doubly linked list of intgr using insertion sort.
* @list: Double pointer to the head of the doubly linked list.
*/
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !(*list)->next)
		return;

	listint_t *current = (*list)->next;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			listint_t *node1 = current->prev;
			listint_t *node2 = current;

			if (node1->prev)
				node1->prev->next = node2;
			else
				*list = node2;

			if (node2->next)
				node2->next->prev = node1;

			node2->prev = node1->prev;
			node1->next = node2->next;
			node2->next = node1;
			node1->prev = node2;

			print_list(*list);
		}
		current = current->next;
	}
}
