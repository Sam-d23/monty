#include "monty.h"
#include <ctype.h>

/**
 * check_for_digit - checks whether a string only contains digits
 * @arg: string to be checked
 * Return: 0 (Success), else 1
 */
static int check_for_digit(char *arg)
{
	int j;

	for (j = 0; arg[j]; j++)
	{
		if (arg[j] == '-' && j == 0)
			continue;
		if (isdigit(arg[j]) == 0)
			return (1);
	}
	return (0);
}

/**
 * m_push - pushes an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 * Return: none
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
