#include "shell.h"
/**
 * main - Simple shell main loop.
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *argv[MAX_NUMBER_ARGUMENTS];
	char *path = getenv("PATH");
	char *full_path;

	while (1)
	{
		printf("Simple shell 0.4+> ");
		fflush(stdout);

		if (!fgets(command, sizeof(command), stdin))
		{
			printf("\n");
			break;
		}

		if (command[strlen(command) - 1] == '\n')
			command[strlen(command) - 1] = '\0';

		if (strlen(command) == 0)
			continue;

		split_command(command, argv);

		if (strcmp(argv[0], "exit") == 0)
			exit(EXIT_SUCCESS);

		if (strcmp(argv[0], "env") == 0)
		{
			print_environment();
			continue;
		}

		full_path = search_path(argv[0], path);
		if (full_path != NULL)
		{
			execute_command(argv);
			free(full_path);
		}
		else
			printf("%s: Command not found\n", argv[0]);
	}
	return (0);
}
