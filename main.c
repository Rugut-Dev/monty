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

			instruction_t instructs[] = {
				{"push", &push},
				{"pall", &pall},
			};

			_getline(argv[1], instructs, sizeof(instructs) /
				 sizeof(instructs[0]));
		}
	}
	return (0);
}
