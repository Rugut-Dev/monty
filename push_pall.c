#include "monty.h"

void push_func(stack_t **head, unsigned int line_num)
{
	int i = 0, num;
	if (global.arg)
	{
		while (global.arg[i])
		{
			if (!isdigit(global.arg[i]))
			{
				char *mess;
				mess = "L%d: usage: push integer\n";
				fprintf(stderr, mess, line_num);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		num = atoi(global.arg);
		addnode(head, num);
	}
}


void addnode(stack_t **head, int num)
{
	stack_t *newnode, *temp;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp = *head;
	newnode->n = num;
	if (temp)
		temp->prev = newnode;

	newnode->next = *head;
	newnode->prev = NULL;
	*head = newnode;
}


void pall_func(stack_t **head, unsigned int line_num)
{
	(void)line_num;
	stack_t *temp;

	temp = *head;
	if (temp == NULL)
		return;
	while(temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
