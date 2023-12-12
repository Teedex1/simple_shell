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
		perror("environ is NULL");
		return (-1);
	}

	for (i = 0; environ[i]; i++)
	{
		if (write(STDOUT_FILENO, environ[i], _strlen(environ[i])) == -1 || write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("ERROR writing to STDOUT_FILENO");
			return (-1);
		}
	}

	return (0);
}
