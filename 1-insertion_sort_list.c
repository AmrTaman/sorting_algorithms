#include "sort.h"

void swap(listint_t *cur, listint_t **list);
/**
 * insertion_sort_list - insertion sort
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = (*list)->next;
	listint_t *mar = cur;
	int count = 1;

	if ((*list) == NULL || (*list)->next == NULL)
		return;
	while (count)
	{
		count = 0;
		while (mar)
		{
			while (1)
			{
				if (cur->prev && cur->n < cur->prev->n)
				{
					swap(cur, list);
					print_list(*list);
					count++;
				}
				else
				{
					break;
				}
			}
			mar = mar->next;
			cur = mar;
		}
	}
}
/**
 * swap - insertion sort
 * @list: list
 * @cur: current
 */
void swap(listint_t *cur, listint_t **list)
{
	listint_t *tmp;

	if (cur->prev->prev == NULL && cur->next == NULL)
	{
		tmp = cur->prev;
		cur->next = tmp;
		cur->prev = NULL;
		tmp->next = NULL;
		tmp->prev = cur;
		(*list) = cur;
	}
	else if (cur->prev->prev == NULL && cur->next != NULL)
	{
		print_list(cur->prev);
		tmp = cur->prev;
		tmp->next = cur->next;
		cur->next->prev = tmp;
		cur->next = tmp;
		cur->prev = NULL;
		tmp->prev = cur;
		(*list) = cur;
	}
	else if (cur->prev->prev != NULL && cur->next == NULL)
	{
		tmp = cur->prev;
		tmp->next = NULL;
		tmp->prev->next = cur;
		cur->next = tmp;
		cur->prev = tmp->prev;
		tmp->prev = cur;
	}
	else
	{
		tmp = cur->prev;
		tmp->next = cur->next;
		tmp->prev->next = cur;
		cur->next->prev = tmp;
		cur->next = tmp;
		cur->prev = tmp->prev;
		tmp->prev = cur;
	}
}
