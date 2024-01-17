#include "monty.h"

/**
 * swap-cSwaps the top two elements of the stack
 * @stack: A pointer to a pointer to the first element of the stack
 * @line_number: the current line number of the file being read
 *
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;
	stack_t *temp;

	holder = (*stack);

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (holder->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = holder->next;
	temp->prev = NULL;
	holder->next = temp->next;
	temp->next = holder;
	holder->prev = temp;
	(*stack) = temp;
}
