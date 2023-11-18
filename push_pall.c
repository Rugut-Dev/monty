#include "monty.h"

/** 
 * push_func - checks global.arg and calls addnode
 * @head: stack head pointer
 * @line_num: file's line number
 */
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
				fclose(global.fp);
				free(global.line_content);
				free_dll(*head);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		num = atoi(global.arg);
		addnode(head, num);
	}
}



/**
 * addnode - adds node in O(1)
 * @head: stack's head
 * @num: data
 */
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



/**
 * pall_func - displays elements in stack LIFO
 * @head: stack head ptr
 * @line_num: unused file's line number
 */
void pall_func(stack_t **head, unsigned int line_num)
{
	(void)line_num;
	stack_t *temp;

	temp = *head;
	if (temp == NULL)
		return;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
