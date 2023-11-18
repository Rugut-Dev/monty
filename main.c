#include "monty.h"

global_t global = {NULL, NULL, NULL};

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} else
	{
		FILE *fp = fopen(argv[1], "r");
		if (!fp)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

		instruction_t instructs[] = {
			{"push", push_func},
			{"pall", pall_func},
			{NULL, NULL}
		};
		_getline(fp, instructs, &stack);
		free_dll(stack);
		fclose(fp);
	}
	return (0);
}

int _getline(FILE *fp, instruction_t *instructs, stack_t **stack) {
    char *line_content = NULL;
    size_t len = 0;
    ssize_t bytes_read = 0;
    unsigned int line_num = 0;
    global.fp = fp;

    while ((bytes_read = getline(&line_content, &len, fp)) != -1) {
        char *opcode_tx;
        int i = 0;

        opcode_tx = strtok(line_content, " \n\t");
        global.arg = strtok(NULL, " \n\t");

        line_num++;
        while (instructs[i].opcode && opcode_tx) {
            if (strcmp(opcode_tx, instructs[i].opcode) == 0) {
                instructs[i].f(stack, line_num);
                break;
            }
            i++;
        }

        if (instructs[i].opcode && opcode_tx == NULL) {
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
