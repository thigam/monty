#include "monty.h"

/**
 * add- Adds the top two elements
 * @stack: A pointer to a pointer to the first element
 * @line_number: The current line number
 *
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *holder = (*stack);

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else if (holder->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	holder->next->n = holder->n + holder->next->n;
	holder->next->prev = NULL;
	(*stack) = holder->next;
	free(holder);
}
