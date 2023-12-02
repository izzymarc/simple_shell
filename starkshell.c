#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * _strcmp - Custom function to compare strings
 * @s1: first string
 * @s2: second string
 * Return: integer difference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((int)(unsigned char)(*s1) - (int)(unsigned char)(*s2));
}

/**
 * execute_command - Executes a command from the shell
 * @input_line: command line input
 */
void execute_command(char *input_line)
{
	char *argv[64]; /* Array for argument tokens */
	char *token;    /* Token pointer */
	int argc = 0;   /* Argument count */
	pid_t pid;      /* Process ID */
	char cmd[1024]; /* Command path */

	/* Tokenize the input line and fill the argument array */
	token = strtok(input_line, " ");
	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL; /* Null-terminate the argument array */

	/* Construct command path */
	snprintf(cmd, sizeof(cmd), "/bin/%s", argv[0]);

	pid = fork(); /* Fork a new process */
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		/* Child process: Execute the command */
		if (execve(cmd, argv, NULL) == -1)
		{
			perror(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process: Wait for the child to complete */
		wait(NULL);
	}
}

/**
 * main - Entry point for the shell
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(void)
{
	char *input_line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2); /* Display a prompt using write */

		nread = getline(&input_line, &len, stdin); /* Read a line from stdin */
		if (nread == -1)
		{
			free(input_line);
			perror("getline");
			return (EXIT_FAILURE);
		}

		/* Remove newline character from input */
		if (input_line[nread - 1] == '\n')
		{
			input_line[nread - 1] = '\0';
		}

		/* Check if the command is "exit" */
		if (_strcmp(input_line, "exit") == 0)
		{
			break;
		}

		/* Execute the command */
		execute_command(input_line);
	}

	free(input_line); /* Free allocated memory */
	return (EXIT_SUCCESS);
}
