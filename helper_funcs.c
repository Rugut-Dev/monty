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

/**
 * char_counter - counts chars to determine size
 * @s_line: points to line
 *
 * Return: num
 */
int char_counter(char *s_line)
{
	int count = 0, i = 0;
	char delim = ' ';

	while (s_line[i] != '\0')
	{
		if (s_line[i] != delim)
		{
			count++;
			while (s_line[i] != '\0' && s_line[i] != delim)
			{
				if (s_line[i + 1] == delim)
				{
					i++;
					continue;
				}
				i++;
			}
		} else
		{
			i++;
		}
	}
	if (s_line[i - 1] == delim)
		count--;

	return (count);
}
