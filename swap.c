#include "monty.h"

/**
 * swap_func - swaps two top most elems in stack
 * @head: headpointer
 * @line_num: line number
 */
void swap_func(stack_t **head, unsigned int line_num)
{
	stack_t *first;
	stack_t *second;
	int data;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free(global.line_content);
		free_dll(*head);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = (*head)->next;
	data = first->n;
	first->n = second->n;
	second->n = data;
}
