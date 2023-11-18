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
 * _getline - reads file and executes opcode
 * @fp: file pointer
 * @instructs: array to function pointers
 * @stack: stack reference
 * Return: 0 on success
 */
int read_line(FILE *fp, instruction_t *instructs, stack_t **stack)
{
	char *line_content = NULL;
	size_t len = 0;
	unsigned int line_num = 0;

	global.fp = fp;

	while (getline(&line_content, &len, fp) != -1)
	{
		char *opcode_tx;

		int i = 0;

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
		if (instructs[i].opcode && opcode_tx == NULL)
		{
			char *mess;

			mess = "L%d: unknown instruction %s\n";
			fprintf(stderr, mess, line_num, opcode_tx);
			fclose(fp);
			free(line_content);
			free_dll(*stack);
			exit(EXIT_FAILURE);
		}
	}
	free(line_content);
	return (0);
}
