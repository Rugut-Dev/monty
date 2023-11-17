#include "monty.h"

global_t global = {NULL, NULL, NULL};

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	} else
	{
		if (access(argv[1], X_OK | F_OK) != 0)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		} else
		{
			instruction_t instructs[] = {
				{"push", push_func},
				{"pall", pall_func},
				{"NULL", NULL}
			};
			_getline(argv[1], instructs, sizeof(instructs) /
				 sizeof(instructs[0]));
		}
	}
	return (0);
}


int _getline(char *av, instruction_t *instructs, size_t size) {
	FILE *fp;
	char *line_content = NULL;
	size_t len = 0, i, j;
	ssize_t bytes_read;
	stack_t **stack = NULL;
	unsigned int line_num = 0;
	fp = fopen(av, "r");
	if (!fp) {
		fprintf(stderr, "Error: Can't open file %s", av);
		exit(EXIT_FAILURE);
	}
	global.fp = fp;

	while ((bytes_read = getline(&line_content, &len, fp)) > 0) {
		char *opcode_tx;

		opcode_tx = strtok(line_content, " \n\t");
		global.arg = strtok(NULL, " \n\t");

		line_num++;
		for (i = 0; i < size; ++i)
		{
			if (strcmp(opcode_tx, instructs[i].opcode) == 0)
			{
				instructs[i].f(stack, line_num);
				break;
			}
			if (instructs[i].opcode == NULL)
			{
				char *message;
				message = "L%d: unknown instruction %s\n";
				fprintf(stderr, message, line_num, opcode_tx);
			}
		}
		free_dll(*stack);
	}
	fclose(fp);
	if (line_content) {
	free(line_content);
	}
	return (0);
}
