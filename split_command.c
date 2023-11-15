#include "shell.h"
/**
 * split_command - Split a command line into arguments.
 * @command: The command line to split.
 * @argv: An array to store the arguments.
 */
void split_command(char *command, char **argv)
{
	char *token;
	int i = 0;


	token = strtok(command, " \t\n");
	while (token != NULL && i < MAX_NUMBER_ARGUMENTS)
	{
		argv[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	argv[i] = NULL;
}
