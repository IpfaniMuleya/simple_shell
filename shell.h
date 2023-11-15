#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUMBER_ARGUMENTS 10

extern char **environ;

void split_command(char *command, char **argv);
void execute_command(char **argv);
char *search_path(char *command, char *path);
void print_environment(void);

#endif
