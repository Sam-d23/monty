#include "monty.h"

/**
 * pall - prints all the stack values
 * @stack: double pointer to the head of the stack
 * @line_number: number of a line of the file
 * Return: none
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	(void) line_number;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
