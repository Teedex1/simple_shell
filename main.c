#include "shell.h"
/**
 * _handler - signal handler
 *
 * @sig:  signal number
 *
void _handler(int sig)
{
	(void)sig;

	write(STDOUT_FILENO, "\n$ ", 3);
}

**
 * main - Entry point for the command line interpreter
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 *
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t line_size = 0;

	(void)argc;
	(void)argv;

	
	if (signal(SIGINT, _handler) == SIG_ERR)
	{
		perror("Error setting up signal handler");
		return (EXIT_FAILURE);
	}


	if (!allocate_memory_for_environ())
	{
		perror("Error allocating memory for environ");
		return (EXIT_FAILURE);
	}

	while (1)
	{
		printf("$ ");

		if (getline(&line, &line_size, stdin) == -1)
		{
			perror("Error reading input");
			free(line);
			break;
		}

		if (strncmp(line, "exit\n", strlen("exit\n")) == 0)
		{
			break;
		}

		execute_command(line);

		free(line);
		line = NULL;
		line_size = 0;
	}

	free_environ();
				
	return (EXIT_SUCCESS);
}

**
 * allocate_memory_for_environ -  Allocates memory for the environment variable
 *
 * Return: Return true
 *
bool allocate_memory_for_environ(void)
{
	environ = realloc(environ, 10 * sizeof(char *));
	return (environ != NULL);
}
*/
#include "shell.h"

/**
 * main - runs a command line interpreter
 * @argc: argument count
 * @argv: array of argument strings
 * Return: 0 on success, or the error code provided by _getline
 * Description: this function's only purpose is to send the correct executable
 * name to the rest of the code for error handling
 */
int main(int argc, char **argv)
{
		(void)argc;
			signal(SIGINT, _handler);
				environ = malloc_array(environ);
					return (_getline(argv[0]));
}
/**
 *  * _handler - prints a new prompt on a newline
 *   * @sig: ignored input
 *    */
void _handler(int sig)
{
		(void)sig;
			write(STDOUT_FILENO, "\n$ ", 3);
}
