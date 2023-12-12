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
	int ret;

	(void)argc;
	
	signal(SIGINT, _handler);
	
	environ = malloc_array(environ);
	if (!environ)
	{
		perror("malloc_array");
		return (1);
	}

	ret = _getline(argv[0]);
	free_array(environ);

	return (ret);
}
/**
 * _handler - prints a new prompt on a newline
 * @sig: ignored input
 */
void _handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
