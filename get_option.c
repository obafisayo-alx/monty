#include "monty.h"

/**
 * get_option - function searches for a match between opcode and text
 * and returns the corresponding function
 * @line: struct containing line and line number
 * @data: struct containing all allocated memory
 *
 * Return: pointer to the matching function
 */
void (*get_option(line_t line, data_t *data))(stack_t **, unsigned int)
{
	size_t i;
	instruction_t options[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	i = 0;
	while (options[i].opcode)
	{
		if (strcmp(options[i].opcode, line.line[0]) == 0)
		{
			push_check(line, data, options[1].opcode);
			if (arg.flag == 1 &&
			strcmp(options[i].opcode, "push") == 0)
			{
				if (line.line)
					free(line.line);
			}
			free(line.line);
			return (options[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line.line_no,
	line.line[0]);
	free(line.line);
	free(data->buff);
	free_stack(&(data->stack));
	fclose(data->fp);
	free(data);
	exit(EXIT_FAILURE);
}
