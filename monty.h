#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct global_s - global variables
 * @arg: data for 'n'
 * @fp: file pointer
 * @line_content: line from getline
 *
 * Description: global declaration for global vars
 */
typedef struct global_s
{
	char *arg;
	FILE *fp;
	char *line_content;
} global_t;
extern global_t global;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char *argv[]);
int _getline(FILE *fp, instruction_t *instructs, stack_t **stack);
void pall_func(stack_t **head, unsigned int line_num);
void addnode(stack_t **head, int num);
void push_func(stack_t **head, unsigned int line_num);
void free_dll(stack_t *head);

#endif
