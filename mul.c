#include "monty.h"

/**
 * _mul- Multiplies the second top with the tope element of the stack
 * @stack: A pointer to a pointer to the first element
 * @line_number: The current line number
 *
 * Return: nothing
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *holder = (*stack);

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else if (holder->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	holder->next->n = holder->next->n * holder->n;
	holder->next->prev = NULL;
	(*stack) = holder->next;
	free(holder);
}
