#include "monty.h"

int _getline(char *av) {
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_num = 0;

	// Open the file for reading
	fp = fopen(av, "r");
	if (!fp) {
		perror("fopen");
		return 1;
	}

	// Read lines from the file and store them in a struct
	while ((read = getline(&line, &len, fp)) != -1) {
		instruction_t *newLine;
		char **wrds;
		wrds = tokenizer(line);

		line_num++;

		newLine = malloc(sizeof(instruction_t));
		
		newLine->opcode = wrds[0];

		// Process the line

		free(newLine->opcode);
		free(newLine);
	}

	// Close the file
	fclose(fp);

	// Free the line buffer
	if (line) {
		free(line);
	}

	return 0;}
