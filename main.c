#include "monty.h"

int main(int argc, char *argv[])
{
	//file opening
	if (argc != 2)
	{
		//HANDLE ERROR
		exit(EXIT_FAILURE);
	} else
	{
		if (access(argv[1], X_OK | F_OK) != 0)
		{
			//HANDLE ERROR
			exit(EXIT_FAILURE);
		} else
		{
			FILE *fp;
			fp = fopen(argv[1],"r");

			// if {NULL -> Cant Open File};

			while (!feof(fp))
			{
				while (getline())
				{
					//read each line
					//tokenize and sort(wordCounter)
					//store line in instruction_t node
				}