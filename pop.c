#include "monty.h"

/**
 * pop- Removes the top element of the stack
 * @stack: A pointer to the pointer to the first element
 * @line_number: The current line number
 *
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *holder = (*stack);
	(void)line_number;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (holder->next == NULL)
	{
		(*stack) = NULL;
	}
	else
	{
		holder->next->prev = NULL;
		(*stack) = holder->next;
		free(holder);
	}
}
