#include "monty.h"

externalarg_t arg = {0, 0};

/**
 * argument_check - verifies argument is valid
 * @token: the argument to be checked
 *
 * Return: true if valid argument, else false
 */
bool args_check(char *token)
{
	unsigned int i;

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * push_check - check if push opcode is being used and sets global
 * argument variable if true
 * @line: struct containing line contents and line number
 * @opcode: the opcode to compare
 * @data: struct containing all allocated memory
 *
 * Return: Nothing.
 */
void push_check(line_t line, data_t *data, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !args_check(line.line[1]))
	{
		free(line.line);
		fprintf(stderr, "L%d: usage: push integer\n", line.line_no);
		free(data->buff);
		free_stack(&(data->stack));
		fclose(data->fp);
		free(data);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.args = atoi(line.line[1]);
}
