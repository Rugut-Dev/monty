#include "monty.h"

char **tokenizer(char *lineptr)
{
	if (lineptr != NULL)
	{
		char *token, **wrds;
		int i = 0, size = 2;
		const char *delim = " ";
		wrds = (char **)malloc(sizeof(char *) * size);
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			wrds[i] = strdup(token);
			i++;

			if (i >= size)
			{
				//HANDLE ERROR
			}
			token = strtok(NULL, delim);
		}
		wrds[i] = NULL;

		return wrds;
	}
	return NULL;
}

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
