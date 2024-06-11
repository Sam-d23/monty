#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EXIT_FAILURE 1

/**
 * _pall_opcode - prints all the values on the stack,
 * starting from the top.
 * @stackPtr: pointer totop of the stack.
 * @line_num: the line number in the file.
 * Return: none
 */

typedef struct stack_s {
    int n;
    struct stack_s *next;
} stack_t;

void push(stack_t **stack, int value, unsigned int line_number);
void pall(stack_t **stack);
int atoi_safe(const char *str, unsigned int line_number);

int main(void) {
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, stdin)) != -1) {
        line_number++;
        char *opcode = strtok(line, " \n\t");
        if (opcode == NULL) {
            continue;
        }

        if (strcmp(opcode, "push") == 0) {
            char *arg = strtok(NULL, " \n\t");
            if (arg == NULL) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            int value = atoi_safe(arg, line_number);
            push(&stack, value, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    while (stack != NULL) {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}

void push(stack_t **stack, int value, unsigned int line_number) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->next = *stack;
    *stack = new_node;
}

void pall(stack_t **stack) {
    stack_t *current = *stack;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int atoi_safe(const char *str, unsigned int line_number) {
    if (str == NULL) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    char *endptr;
    long val = strtol(str, &endptr, 10);

    if (*endptr != '\0' || str == endptr) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    return (int) val;
}

