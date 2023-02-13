#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a given position
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 otherwise
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *temp, *prev, *next;

	if (!head || !*head)
		return (-1);

	temp = *head;
	for (i = 0; temp && i < index; i++)
		temp = temp->next;
	if (!temp)
		return (-1);

	prev = temp->prev;
	next = temp->next;
	if (prev)
		prev->next = next;
	else
		*head = next;
	if (next)
		next->prev = prev;
	free(temp);
	return (1);
}
