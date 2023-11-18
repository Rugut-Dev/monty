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
 * my_getline - custom getline
 * @fp: file pointer
 * @line_content: line content
 * @len: size of line
 * Return: int
 */
int my_getline(FILE *fp, char **line_content, size_t *len)
{
	size_t line_size = 1024;
	char *temp_buffer = malloc(line_size), *new_line_content;
	size_t line_length = 0;
	int c;

	while ((c = fgetc(fp)) != EOF)
	{
		if (line_length + 1 > line_size)
		{
			line_size *= 2;
			temp_buffer = realloc(temp_buffer, line_size);
		}
		temp_buffer[line_length] = (char) c;
		line_length++;
		if (c == '\n')
			break;
	}
	if (c == EOF)
	{
		free(temp_buffer);
		*line_content = NULL;
		*len = 0;
		return (-1);
	}

	new_line_content = malloc(line_length + 1);

	memcpy(new_line_content, temp_buffer, line_length);
	new_line_content[line_length] = '\0';

	free(temp_buffer);
	*line_content = new_line_content;
	*len = line_length;

	return (0);
}
