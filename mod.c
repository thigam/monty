#include "monty.h"

/**
 * _mod- computes the rest of the division of the second top element of
 * the stack by the top element of the stack
 * @stack: A pointer to a pointer to the first element
 * @line_number: The current line number
 *
 * Return: nothing
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *holder = (*stack);

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else if (holder->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	
	if (holder->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	holder->next->n = holder->next->n % holder->n;
	holder->next->prev = NULL;
	(*stack) = holder->next;
	free(holder);
}
