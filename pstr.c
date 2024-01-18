#include "monty.h"

/**
 * _pstr- Prints the string starting at the top of the stack, followed by a new line
 * @stack: A pointer to a pointer to the first element
 * @line_number: The line numbe rof the current instruction
 *
 * Return: nothing
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *holder = (*stack);
	(void)line_number;

	while (holder)
	{
		if (holder->n < 1 || holder->n > 255)
			break;

		printf("%c", holder->n);
		holder = holder->next;
	}

	printf("\n");
}
