#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shake);
void cocktail_sort_list(listint_t **list);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shake);

/**
 * swap_node_ahead - To swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shake: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shake)
{
	listint_t *temp = (*shake)->next;

	if ((*shake)->prev != NULL)
		(*shake)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shake)->prev;
	(*shake)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shake;
	else
		*tail = *shake;
	(*shake)->prev = temp;
	temp->next = *shake;
	*shake = temp;
}

/**
 * swap_node_behind - To swap a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shake: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shake)
{
	listint_t *temp = (*shake)->prev;

	if ((*shake)->next != NULL)
		(*shake)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shake)->next;
	(*shake)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shake;
	else
		*list = *shake;
	(*shake)->next = temp;
	temp->prev = *shake;
	*shake = temp;
}

/**
 * cocktail_sort_list - To sort a listint_t doubly-linked list of integers in
 * ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shake;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shake = *list; shake != tail; shake = shake->next)
		{
			if (shake->n > shake->next->n)
			{
				swap_node_ahead(list, &tail, &shake);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shake = shake->prev; shake != *list;
				shake = shake->prev)
		{
			if (shake->n < shake->prev->n)
			{
				swap_node_behind(list, &tail, &shake);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
