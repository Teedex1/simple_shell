#include "shell.h"
/**
 * _getenv - custom implementation of getenv
 * Description: Retrives the value of a specified env variable
 * @name: name of the env variable
 * Return: NULL
 */
char *_getenv(const char *name)
{
	int i;
	size_t name_len = _strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
			return (environ[i] + name_len + 1);
	}

	return (NULL);
}
/**
 * env_index - finds the index in env
 * @name: environmental variable
 * Return: Index of environ where is found
 */
int env_index(const char *name)
{
	int i;
	size_t name_len = _strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
			return (i);
	}

	return (-1);
}
