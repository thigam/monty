#include "monty.h"

/**
 * main- Executes monty code instructions
 * @argc: Number of command line arguments
 * @argv: A pointer to an array of pointers to command line arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char buffer[100];
	/*size_t getline_value = 0;*/
	char *opcode, *par;
	int line_num = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		line_num++;
		opcode = strtok(buffer, " \n");
		par = strtok(NULL, " \n");

		if (switchboard(opcode, line_num, &stack, par) == -1)
		{
			fprintf(stderr, "L%d: unkown instruction %s\n", line_num, opcode);
			fclose(file);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	free_stack(&stack);

	return (0);
}
