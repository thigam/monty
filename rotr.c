#include "monty.h"

/**
 * _rotr- Rotates the stack to the bottom
 * @stack: A pointer to a pointer to the top element in the stack
 * @line_number: The line number of the currently executing instruction
 *
 * Return: nothing
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack);
	stack_t *holder_first = (*stack);
	stack_t *holder_last;
	(void)line_number;

	if ((*stack) == NULL)
		return;

	if (holder_first->next == NULL)
		return;

	while (temp)
	{
		holder_last = temp;
		temp = temp->next;
	}

	(*stack) = holder_last;
	holder_last->prev->next = NULL;
	holder_last->prev = NULL;
	holder_last->next = holder_first;
	holder_first->prev = holder_last;
}
