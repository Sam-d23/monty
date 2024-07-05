#include "monty.h"
/**
 * f_pall - Function that prints the stack
 * @head: stack's head
 * @counter: not used
 * Return: None
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
