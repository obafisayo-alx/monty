#include "monty.h"

/**
 * main - main entry point, opens monty script for read
 * @ac: argument count
 * @av: argument vectors
*/
int main(int ac, char *av[])
{
	FILE *fp;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = open(av[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	parsefp(fp);
	return (EXIT_SUCCESS);
}
