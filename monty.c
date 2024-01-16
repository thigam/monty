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
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", argv[1]);
	}
	
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		line_num++;
		opcode = strtok(buffer, " \n");
		par = strtok(NULL, " \n");

		if (switchboard(opcode, par, &stack) == -1)
		{
			fprintf(stderr, "L%d: unkown instruction %s\n", line_num, opcode);
		}
	}

	return (0);
}

int switchboard(char *opcode, char *par, stack_t **stack)
{
	instruction_t list[] = {
		{"push", push},
		{"pall", pall}
	};
	int counter = 0;

	while (counter < 2)
	{
		if (par == NULL && strcmp(list[counter].opcode, opcode) == 0)
		{
			list[counter].f(stack, 0);
			return (0);
		}
		else if (strcmp(list[counter].opcode, opcode) == 0)
		{
			list[counter].f(stack, atoi(par));
			return (0);
		}
		counter++;
	}
	return (-1);
}

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;
	stack_t *new;

	holder = *stack;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (holder == NULL)
	{
		new->n = line_number;
		new->prev = NULL;
		new->next = NULL;
		(*stack) = new;
	}
	else
	{
		new->n = line_number;
		new->prev = NULL;
		new->next = holder;
		holder->prev = new;
		(*stack) = new;
	}

	return;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	holder = *stack;
	line_number++;

	while (holder != NULL)
	{
		printf("%d\n", holder->n);
		holder = holder->next;
	}

	return;
}
