#include "monty.h"

typedef struct {
	char *data;
} Line;

int _getline(char *av) {
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	// Open the file for reading
	fp = fopen(av, "r");
	if (!fp) {
		perror("fopen");
		return 1;
	}

	// Read lines from the file and store them in a struct
	while ((read = getline(&line, &len, fp)) != -1) {
		instruction_t *newLine;
		newLine = malloc(sizeof(instruction_t));
		
		newLine->data = strdup(line);

		// Process the line
		printf("%s", newLine->data);

		free(newLine->data);
		free(newLine);
	}

	// Close the file
	fclose(fp);

	// Free the line buffer
	if (line) {
		free(line);
	}

	return 0;}
