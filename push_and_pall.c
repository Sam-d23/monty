#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 1024

/**
 * push - runs opcode push
 * @value: integer value
 * @line_number: the line number
 * Return: none
 */
void push(int value, int line_number)
{
	if (stack.top == STACKSIZE - 1)
	{
		fprintf(stderr, "L%d: Error: Stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack.top++;
	stack.stack[stack.top] = value;
}
/**
 * pall - runs opcode pall
 * @line_number: the line number
 * Return: none
 */
void pall(int line_number)
{
	int i;

	for (i = stack.top; i >= 0; i--)
	{
		printf("%d\n", stack.stack[i]);
	}
}
/**
 * main - executes the push and pall opcodes
 * Return: none
 */
int main(void)
{
	char opcode[4];
	int value;
	int line_number = 1;

	stack.top = -1;

	while (scanf("%s", opcode) != EOF)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (scanf("%d", &value) != 1)
			{
				fprintf(stderr, "L%d: Error: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(value, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(line_number);
		}
		else
		{
			fprintf(stderr, "L%d: Error: Unknown opcode '%s'\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		line_number++;
	}

	return (0);
}
