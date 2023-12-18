#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: the pointer to the head of the stack
 * @nline: the line number we are on
 * Return: void
*/
void pchar(stack_t **stack, unsigned int nline)
{
	char c;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}

	c = temp->n;
	if (_isalpha(temp->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
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
	(void)nline;

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
	stack_t *temp;
	int hold_this;
	(void)nline;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		nop(stack, nline);
		return;
	}

	hold_this = (*stack)->n;

	temp = *stack;
	while (temp->next)
		temp = temp->next;

	(*stack)->n = temp->n;
	temp->n = hold_this;
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
	(void)nline;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		nop(stack, nline);
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
