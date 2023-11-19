#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variables - global variables that are accessible to all files.
 * @oc_arg: pointer to arg of opcode.
 * @buf: pointer to buffer for the line in opened files.
 * @fd: file descriptor;
 * Description: global variables used to construct our stack
 */
typedef struct global_variables
{
	char *oc_arg;
	char *buf;
	FILE *fd;
} glob_var;

glob_var *c;

void _geterrmsg(int f, unsigned int line_num, stack_t **stackPtr);
void reclaim_mem(stack_t **stackPtr, int f);
int _isdigit(unsigned int line_num, stack_t **stackPtr);
void _push_opcode(stack_t **stackPtr, unsigned int line_num);
void _pall_opcode(stack_t **stackPtr, unsigned int line_num);
stack_t *_getOpFunc(stack_t **stackPtr, char *oc, unsigned int l_num);
void _pint_opcode(stack_t **stackPtr, unsigned int l_num);
void _pop_opcode(stack_t **stackPtr, unsigned int l_num);
void _swap_opcode(stack_t **stackPtr, unsigned int l_num);
void _add_opcode(stack_t **stackPtr, unsigned int l_num);
void _nop_opcode(stack_t **stackPtr, unsigned int l_n);
void _sub_opcode(stack_t **stackPtr, unsigned int l_num);
void _div_opcode(stack_t **stackPtr, unsigned int l_num);
void _mul_opcode(stack_t **stackPtr, unsigned int l_num);
void _mod_opcode(stack_t **stackPtr, unsigned int l_num);
void _pchar_opcode(stack_t **stackPtr, unsigned int l_num);
void _pstr_opcode(stack_t **stackPtr, unsigned int l_num);
void _rotl_opcode(stack_t **stackPtr, unsigned int l_num);
void _rotr_opcode(stack_t **stackPtr, unsigned int l_num);
#endif
