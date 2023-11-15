#include "shell.h"
/**
 * execute_command - Execute a command with arguments.
 * @argv: An array containing the command and its arguments.
 */
void execute_command(char **argv)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, &status, 0);
}
