#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line_s - A line of a file and its corresponding number
 * @line: The line to be read
 * @line_no: The corresponding line number
 * 
 * Description: Line of a file and its corresponding number
*/
typedef struct line_s
{
	char **line;
	unsigned int line_no;
} line_t;

/**
 * struct data_s - stores data gotten from a file and maintains its stack
 * @buff: the buffer to be read
 * @fp: The file pointer of the file
 * @stack: the stack to be maintained
 * 
 * Description: For storing data from file and maintaing stack
*/
typedef struct data_s
{
	char *buff;
	FILE *fp;
	stack_t *stack;
} data_t;

/**
 * struct externalarg_s - exter arguments
 * @flag: argument 2
 * @args: argument 1
 * 
 * Description: contains extern arguments
*/
typedef struct externalarg_s
{
	int args;
	int flag;
} externalarg_t;

extern externalarg_t arg;

void (*get_option(line_t line, data_t *data))(stack_t **, unsigned int);

void parsefp(FILE *file);
void _parsefp(line_t *line, char *buffer);

void push_check(line_t line, data_t *data, char *opcode);
bool args_check(char *token);

void push(stack_t **stack, unsigned int nline);
void free_stack(stack_t **stack);

#endif
