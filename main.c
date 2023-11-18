#include "monty.h"

global_t global = {NULL, NULL, NULL};

/**
 * main - main func
 * @argc: cmd args counter
 * @argv: cmd args array
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t *stack = NULL;
	instruction_t instructs[] = {
		{"push", push_func},
		{"pall", pall_func},
		{NULL, NULL}
	};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} else
	{
		fp = fopen(argv[1], "r");
		if (!fp)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

		read_line(fp, instructs, &stack);
		free_dll(stack);
		fclose(fp);
	}
	return (0);
}


/**
 * read_line - reads file and executes opcode
 * @fp: file pointer
 * @instructs: array to function pointers
 * @stack: stack reference
 * Return: 0 on success
 */
int read_line(FILE *fp, instruction_t *instructs, stack_t **stack)
{
	char *line_content = NULL, *opcode_tx;
	unsigned int line_num = 0;
	int max_line_length = 1024, i = 0, line_size;

	while (1)
	{
		line_content = malloc(max_line_length * sizeof(char));
		if (line_content == NULL)
			malloc_fail();
		if (fgets(line_content, max_line_length, fp) == NULL)
		{
			free(line_content);
			break;
		}
		line_size = char_counter(line_content) + 1;
		if (line_size > max_line_length)
		{
			max_line_length = line_size;
			free(line_content);
			continue;
		}
		opcode_tx = strtok(line_content, " \n\t");
		global.arg = strtok(NULL, " \n\t");
		line_num++;
		while (instructs[i].opcode && opcode_tx)
		{
			if (strcmp(opcode_tx, instructs[i].opcode) == 0)
			{
				instructs[i].f(stack, line_num);
				break;
			}
			i++;
		}
		if (instructs[i--].opcode && opcode_tx == NULL)
			_isNull(fp, line_content, stack, opcode_tx, line_num);
		free(line_content);
	}
	return (0);
}

/**
 * _isNull - checks if iterator reached NULL in instructs array
 * @fp: file pointer
 * @line_content: line
 * @stack: stack ptr
 * @opcode_tx: opcode
 * @line_num: line number
 */
void _isNull(FILE *fp, char *line_content, stack_t  **stack,
	     char *opcode_tx, unsigned int line_num)
{
	char *mess;

	mess = "L%d: unknown instruction %s\n";
	fprintf(stderr, mess, line_num, opcode_tx);
	fclose(fp);
	free(line_content);
	free_dll(*stack);
	exit(EXIT_FAILURE);
}

/**
 * malloc_fail - if malloc fails
 *
 */
void malloc_fail(void)
{
	fprintf(stderr, "Memory allocation failed.\n");
	exit(EXIT_FAILURE);
}
