#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **switcher);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **switcher);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @switcher: A pointer to the current swapping node of the cocktail switcher algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **switcher)
{
	listint_t *tmp = (*switcher)->next;

	if ((*switcher)->prev != NULL)
		(*switcher)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*switcher)->prev;
	(*switcher)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *switcher;
	else
		*tail = *switcher;
	(*switcher)->prev = tmp;
	tmp->next = *switcher;
	*switcher = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with a node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @switcher: A pointer to the current swapping node of a cocktail switcher algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **switcher)
{
	listint_t *tmp = (*switcher)->prev;

	if ((*switcher)->next != NULL)
		(*switcher)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*switcher)->next;
	(*switcher)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *switcher;
	else
		*list = *switcher;
	(*switcher)->next = tmp;
	tmp->prev = *switcher;
	*switcher = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail switcher algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *switcher;
	bool switched_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (switched_not_stirred == false)
	{
		switched_not_stirred = true;
		for (switcher = *list; switcher != tail; switcher = switcher->next)
		{
			if (switcher->n > switcher->next->n)
			{
				swap_node_ahead(list, &tail, &switcher);
				print_list((const listint_t *)*list);
				switched_not_stirred = false;
			}
		}
		for (switcher = switcher->prev; switcher != *list;
				switcher = switcher->prev)
		{
			if (switcher->n < switcher->prev->n)
			{
				swap_node_behind(list, &tail, &switcher);
				print_list((const listint_t *)*list);
				switched_not_stirred = false;
			}
		}
	}
}
