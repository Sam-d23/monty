#include "monty.h"

/**
 * push - runs opcode push
 * @stack: pointer to stack
 * @value: value to be pushed
 * Return: none
 */
void push(Stack *stack, int value)
{
	if (stack->top == STACK_SIZE - 1)
	{
		fprintf(stderr, "Error: Stack overflow\n");
		exit(EXIT_FAILURE);
	}

	stack->stack[++stack->top] = value;
}

/**
 * pall - runs opcode pall
 * @stack: pointer to stack
 * Return: none
 */
void pall(Stack *stack)
{
	int i;

	for (i = stack->top; i >= 0; i--)
	{
		printf("%d\n", stack->stack[i]);
	}
}
