#include "monty.h"

/**
 * _pchar- Prints the char at the top of the stack followed by a new line
 * @stack: A pointer to a pointer to the first element
 * @line_number: The current instruction's line number
 *
 * Return: nothing
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *holder = (*stack);

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (holder->n > 255 || holder->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", holder->n);
}
