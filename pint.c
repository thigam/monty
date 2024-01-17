#include "monty.h"

/**
 * pint- Prints the value at the top of the stack
 * @stack: A pointer to the pointer to the first node
 * @line_number: The current line number
 *
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *holder = *stack;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", holder->n);
}
