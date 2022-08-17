#include "sort.h"

/**
 * insertion_sort_list - sorting a doubly linked list of int
 *
 * @list: list to sort
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back, *curr;

	back = node->prev;
	curr = node;

	back->next = curr->next;
	if (curr->next)
		curr->next->prev = back;
	curr->next = back;
	curr->prev = back->prev;
	back->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}
