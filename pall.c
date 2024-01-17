#include "monty.h"

/**
 * pall- Prints all the values from the stack starting from the top of the stack
 * @stack: A pointer to the pointer to the first element of the doubly linked list
 * @line_number: 0
 *
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	holder = *stack;
	line_number++;

	while (holder != NULL)
	{
		printf("%d\n", holder->n);
		holder = holder->next;
	}

	return;
}
