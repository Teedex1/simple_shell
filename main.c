#include "shell.h"
/**
 * main - Entry point for the command line interpreter
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t line_size = 0;

	(void)argc;
	(void)argv;

	/** char *line = _getline(argv[0]); */
	
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

		if (strcmp(line, "exit\n") == 0)
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
/**
 * @brief Signal handler for SIGINT (Ctrl+c)
 *
 * @param sig signal number (ignored)
 
void _handler(int sig)
{
	(void)sig;

	write(STDOUT_FILENO, "\n$ ", 3);
}**
 * @brief Allocates memory for the environment variable
 *
 * Return Return true
 *
bool allocate_memory_for_environ(void)
{
	environ = realloc(environ, 10 * sizeof(char *));
	return (environ != NULL);
}
*/
