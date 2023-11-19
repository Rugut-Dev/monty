#include "monty.h"

/**
 * nop_func - does nothing
 * @head: head ptr
 * @line_num: line number
 *
 */
void nop_func(stack_t **head, unsigned int line_num)
{
	(void)*head;
	(void)line_num;

	return;
}
