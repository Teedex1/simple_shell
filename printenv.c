#include "shell.h"
/**
 *  _printenv - prints the environment using environ
 *  Return: 0 on success
 */
int _printenv(void)
{
	int i;

	if(!environ)
	
	{
		fprintf(stderr, "Error: environ is NULL\n");
		return (-1);
	}

	for (i = 0; environ[i]; i++)
	{
		if (write(STDOUT_FILENO, environ[i], _strlen(environ[i])) == -1 || write(STDOUT_FILENO, "\n", 1) == -1)
		{
			fprintf(stderr, "ERROR writing to STDOUT_FILENO for environment variable: %s\n", environ[i]);
			return (-1);
		}
	}

	return (0);
}
