#include "monty.h"
/**
 * _pall_opcode - prints all the values on the stack,
 * starting from the top.
 * @stackPtr: pointer totop of the stack.
 * @line_num: the line number in the file.
 * Return: none
 */
void _pall_opcode(stack_t **stackPtr, unsigned int line_num)
{
	stack_t *temp = *stackPtr;

	line_num += 0;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
