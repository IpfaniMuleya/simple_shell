#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>
/**
 * search_path - Search for the command in the PATH directories.
 * @command: The command to search for.
 * @path: The PATH environment variable.
 * Return: The full path of the command if found, NULL otherwise.
 */
char *search_path(char *command, char *path)
{
	struct stat st;
	char *token;
	char *full_path;
	const char *delimiter = ":";

	if (command[0] == '/')
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		else
			return (NULL);
	}

	if (stat(command, &st) == 0)
		return (strdup(command));

	token = strtok(path, delimiter);
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (stat(full_path, &st) == 0)
			return (full_path);

		free(full_path);
		token = strtok(NULL, delimiter);
	}
	return (NULL);
}
