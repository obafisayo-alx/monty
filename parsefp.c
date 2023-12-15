#include "monty.h"

void parsefp(FILE *fp);
void _parsefp(line_t *line, char *buffer);

/**
 * parsefp - parse the file being read from the file ptr fp one line at a time
 * @fp: file pointer of the file to be read
 * 
 * Return: void
*/
void parsefp(FILE *fp)
{
	size_t n = 0, i = 0;
	data_t *data = NULL;
	line_t line;

	data = malloc(sizeof(data_t));
	if (!data)
	{
		fprintf(stderr, "Error: malloc failed");
		free(data->buff);
		exit(EXIT_FAILURE);
	}
	line.line = NULL;
	line.line_no = 0;
	data->fp = fp;
	data->buff = NULL;
	data->stack = NULL;
	while (getline(&(data->buff), &n, data->fp) != -1)
	{
		line.line_no = line.line_no + 1;
		_parsefp(&line, data->buff);
		if (line.line)
		{
			for (i = 0; line.line[i] != NULL; i++)
				printf("%s ", line.line[i]);
		}
		free(line.line);
	}
	free(data->buff);
	free_stack(&(data->stack));
	fclose(data->fp);
	free(data);
}

void _parsefp(line_t *line, char *buffer)
{
	size_t i;
	char *token = NULL;

	line->line = malloc(sizeof(char *) * 3);
	if (!line->line)
	{
		fprintf(stderr, "Error: malloc failed");
		free(line->line);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " '\n'");
	for (i = 0; token && i < 2; i++)
	{
		line->line[i] = token;
		token = strtok(NULL, " '\n'");
	}
	line->line[i] = NULL;
}