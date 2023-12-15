#include "monty.h"

/**
 * free_stack - frees all the nodes in a stack
 * @stack: pointer to the first node of the stack
 * 
 * Return: void
*/
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
		return;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	
}