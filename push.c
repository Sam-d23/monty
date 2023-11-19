#include "monty.h"
/**
 * _push_opcode - function to execute the push opcode.
 * @stackPtr: pointer to top of the stack.
 * @line_num: line number in the file.
 * Return: void
 */
void _push_opcode(stack_t **stackPtr, unsigned int line_num)
{
	stack_t *new_node = NULL;
	int mod_int = 0, check = 0;

	line_num += 0;
	check = _isdigit(line_num, stackPtr);
	if (check == 0)
		_geterrmsg(2, line_num, stackPtr);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		_geterrmsg(2, line_num, stackPtr);
	new_node->prev = NULL;
	new_node->next = NULL;
	mod_int = atoi(c->oc_arg);
	new_node->n = mod_int;

	if (*stackPtr != NULL)
	{
		(*stackPtr)->prev = new_node;
		new_node->next = *stackPtr;
		*stackPtr = new_node;
	}
	*stackPtr = new_node;
}

/**
 * _isdigit - checks for a digit.
 * @line_num: line number in the file.
 * @stackPtr: pointer to top of the file.
 * Return: 1 if digit is read, 0 otherwise.
 */
int _isdigit(unsigned int line_num, stack_t **stackPtr)
{
	int j = 0;

	if (c->oc_arg == NULL)
		_geterrmsg(2, line_num, stackPtr);
	while (c->oc_arg[j] != '\0')
	{
		if ((c->oc_arg[j] < 48 || c->oc_arg[j] > 57) && c->oc_arg[j] != 45)
			return (0);
		j++;
	}
	return (1);
}
