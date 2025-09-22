#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a specific index in a doubly linked list.
 * @head: A pointer to the pointer to the first node of the list.
 * @index: The index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int i = 0;

    if (*head == NULL)
        return (-1);

    /* Traverse the list to find the node at the given index */
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    /* If the index is out of range, return -1 */
    if (current == NULL)
        return (-1);

    /* If the node to delete is the head node */
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        /* Update the previous node's next pointer */
        if (current->prev != NULL)
            current->prev->next = current->next;

        /* Update the next node's prev pointer */
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
