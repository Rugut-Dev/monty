#include "monty.h"

/**
 * pop_func - pops top num of stack
 * @head: head pointer
 * @line_num: line number
 *
 */
void pop_func(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free(global.line_content);
		free_dll(*head);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
}
