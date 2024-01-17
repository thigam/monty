#include "monty.h"

/**
 * push- Adds an element to the beginning of the 'stack'
 * @stack: A pointer to the pointer to the stack's first element
 * @line_number: The integer to be held in the new element
 *
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;
	stack_t *new;

	if (par == NULL || (atoi(par) == 0 && par[0] != '0'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	holder = *stack;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (holder == NULL)
	{
		new->n = atoi(par);
		new->prev = NULL;
		new->next = NULL;
		(*stack) = new;
	}
	else
	{
		new->n = atoi(par);
		new->prev = NULL;
		new->next = holder;
		holder->prev = new;
		(*stack) = new;
	}
}
