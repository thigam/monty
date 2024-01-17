#include "monty.h"

/**
 * switchboard- Selects and calls the corresponding function based on opcode
 * @opcode: The string represent the required operation
 * @line_num: The current line number of the source file
 * @stack: A pointer to the pointer to the first element
 * in the doubly linked list
 *
 * Return: 0 if successful, -1 if no correspodning function is found
 */

int switchboard(char *opcode, int line_num, stack_t **stack, char *par)
{
	instruction_t list[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add}
	};
	int counter = 0;

	while (counter < 6)
	{
		if (strcmp("nop", opcode) == 0)
			;
		else if (strcmp("push", opcode) == 0)
		{
			push(stack, line_num, par);
			return (0);
		}
		else if (strcmp(list[counter].opcode, opcode) == 0)
		{
			list[counter].f(stack, line_num);
			return (0);
		}
		counter++;
	}
	return (-1);
}
