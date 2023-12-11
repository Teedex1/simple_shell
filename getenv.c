#include "shell.h"
/**
 * _strncmp - string comparison functiom
 * @s1: first string
 * @s2: second string
 * Return: 0
 */
int custom_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	int result;
	unsigned char u1, u2;

	for (i = 0; i < n; ++i)
	{
		u1 = (unsigned char)s1[i];
		u2 = (unsigned char)s2[i];

		if (u1 != u2)
		{
			result = (int)u1 - (int)u2;
			return (result);
		}

		if (u1 == '\0')
			break;
	}

	return (0);
}

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
		if (custom_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
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
		if (custom_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
			return (i);
	}

	return (-1);
}
