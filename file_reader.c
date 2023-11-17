#include "monty.h"

int _getline(char *av, instruction_t *instructs, size_t size) {
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_num = 1;

	// Open the file for reading
	fp = fopen(av, "r");
	if (!fp) {
		//perror("fopen");
		exit(EXIT_FAILURE);
	}
	// Read lines from the file and store them in a struct
	while ((read = getline(&line, &len, fp)) != -1) {

		char **wrds, char *opcode_tx;
		wrds = tokenizer(line);

		opcode_tx = wrds[0];

		if (opcode_tx[strlen(opcode_tx) - 1] == "\n")
			opcode_tx[strlen(opcode_tx) - 1] = "\0";

		for (size_t i = 0; i < size; ++i) {
			if (strcmp(opcode_tx, instructs[i]->opcode) == 0) {
				instructs[i]->f(NULL, line_num);
				break;
			}
		}
		line_num++;
	}

	// Close the file
	fclose(fp);

	// Free the line buffer
	if (line) {
	free(line);
	}

	return 0;}
