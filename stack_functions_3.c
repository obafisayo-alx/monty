#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: the pointer to the head of the stack
 * @nline: the line number we are on
 * Return: void
*/
void pchar(stack_t **stack, unsigned int nline)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
		exit(EXIT_FAILURE);
	}
	if (_isalpha((*stack)->n))
		printf("%c\n", (*stack)->n);
}

/**
 * pstr -  prints the string starting at the top of the stack
 * @stack: the pointer to the head of the stack
 * @nline: the line number
 * Return: void
*/
void pstr(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "\n");
		return;
	}
	temp = *stack;
	while (temp != NULL && temp->n != 0 && _isalpha(temp->n))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: the pointer to the head of the stack
 * @nline: the line number
 * Return: void
*/
void rotl(stack_t **stack, unsigned int nline)
{
	stack_t *temp, *node;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "\n");
		return;
	}
	temp = node = *stack;
	*stack = (*stack)->next;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	node->next = NULL;
	node->prev = temp;
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: the pointer to the head of the stack
 * @nline: the line number
 * Return: void
*/
void rotr(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "\n");
		return;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}


