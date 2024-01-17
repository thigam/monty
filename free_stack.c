#include "monty.h"

/**
 * free_stack- Frees the elements of a stack
 * @stack: A pointer to the stack
 *
 * Return: nothing
 */

void free_stack(stack_t **stack)
{
	stack_t *holder = (*stack);
	stack_t *temp;

	if ((*stack) == NULL)
		return;

	while (holder != NULL)
	{
		temp = holder->next;
		free(holder);
		holder = temp;
	}
	(*stack) = NULL;
}
