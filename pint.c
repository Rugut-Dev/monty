#include "monty.h"

/**
 * pint_func - prints num on top of stack
 * @head: head pointer
 * @line_num: line number
 *
 */
void pint_func(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free(global.line_content);
		free_dll(*head);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
