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

int switchboard(char *opcode, int line_num, stack_t **stack)
{
	instruction_t list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop}
	};
	int counter = 0;

	while (counter < 4)
	{
		if (strcmp(list[counter].opcode, opcode) == 0)
		{
			list[counter].f(stack, line_num);
			return (0);
		}
		counter++;
	}
	return (-1);
}
