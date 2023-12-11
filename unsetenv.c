#include "shell.h"
/**
 * _unsetenv - to unset env
 * @name: pointer  name
 * 
 * Return: 0
 *
 */
int _unsetenv(const char *name)
{
	int i = 0;

	if (!environ || !name)
	{
		return (-1);
	}

	while (environ[i])
	{
		if (custom_strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			break;
		}
		i++;
	}
	if (!environ[i])
	{
		return (1);
	}

	free(environ[i]);

	for (; environ[i + 1]; i++)
	{
		environ[i] = environ[i + 1];
	}

	environ = _reallocf(environ, sizeof(char *) * (i + 2), sizeof(char *) * (i + 1));
	if (!environ)
	{
		return (-1);
	}
	return (0);
}

