#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL)
    {
        return (-1);
    }

    dlistint_t *current = *head;
    unsigned int i = 0;

    while (i < index && current != NULL)
    {
        current = current->next;
        i++;
    }

    if (i != index || current == NULL)
    {
        return (-1);
    }

    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        current->prev->next = current->next;
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
