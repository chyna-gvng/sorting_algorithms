#include "sort.h"

/**
 * _swap - swap current node
 * @prmCurrent: current node
 * @prmAfter: next node
 * @prmList: original list
 * Return: nothing void
 */

void _swap(listint_t *prmCurrent, listint_t *prmAfter, listint_t **prmList)
{
	listint_t *before, *after;

	if (prmCurrent == NULL || prmAfter == NULL)
		return;

	before = prmCurrent->prev;
	after  = prmAfter->next;

	if (before != NULL)
		before->next = prmAfter;
	else
		*prmList = prmAfter;

	if (after != NULL)
		after->prev = prmCurrent;

	prmCurrent->next = after;
	prmCurrent->prev = prmAfter;
	prmAfter->next = prmCurrent;
	prmAfter->prev = before;

	print_list(*prmList);
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to list to sort
 * Return: nothing void
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *head = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		while (head->next != NULL)
		{
			if (head->n > head->next->n)
			{
				_swap(head, head->next, list);
				swapped = 1;
				continue;
			}
			head = head->next;
		}

		swapped = 0;
		head = head->prev;

		while (head->prev != NULL)
		{
			if (head->n < head->prev->n)
			{
				_swap(head->prev, head, list);
				swapped = 1;
				continue;
			}
			head = head->prev;
		}
		head = head->next;
	} while (swapped == 1);
}
