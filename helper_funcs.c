#include "monty.h"

/**
 * free_dll - frees whole stack
 * @head: start pointer
 *
 */
void free_dll(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;

		free(head);
		head = temp;
	}
}
