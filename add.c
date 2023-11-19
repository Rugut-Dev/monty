#include "monty.h"

/**
 * add_func - adds the two top most elems in stack
 * @head: headpointer
 * @line_num: line number
 */
void add_func(stack_t **head, unsigned int line_num)
{
	stack_t *first;
	stack_t *second;
	int res;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free(global.line_content);
		free_dll(*head);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second =  (*head)->next;
	res = (first->n) + (second->n);
	second->n = res;
	pop_func(head, line_num);
}
