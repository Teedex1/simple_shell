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
	bool found = false;
	char **resized_environ;
	size_t num_elements_to_move;

	if (!environ || !name)
	{
		return (-1);
	}

	while (environ[i])
	{
		if (custom_strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			found = true;
			break;
		}
		i++;
	}
	
	if (!found)
	{
		return (0);
	}

	free(environ[i]);

	num_elements_to_move = array_length(environ) - i;

	memmove(&environ[i], &environ[i + 1], sizeof(char *) * num_elements_to_move);

	resized_environ = _reallocf(environ, sizeof(char *) * (i + 2), sizeof(char *) * (i + 1));
	if (!resized_environ)
	{
		return (-1);
	}
	environ = resized_environ;

	return (0);
}

