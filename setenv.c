#include "shell.h"
/**
 * _reallocates - a memory block without freeing the old one.
 *
 * @param ptr pointer to the previous memory allocation
 * @param old_size - Size, in bytes, of the spaces allocated to ptr.
 * @param new_size - Size, in the bytes, of the new memory block
 * Return: Pointer to the new memory block
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		perror("_realloc");
		return (NULL);
	}

	if (ptr)

	{
		memcpy(new_ptr, ptr, (old_size < new_size) ? old_size : new_size);
		free(ptr);
	}
	
	return (new_ptr);
}
/**
 * _reallocf - a memory block, freeing the old one.
 *
 * @ptr: Pointer to the previous memory allocation
 * @old_size: Size in bytes.
 * @new_size: size in bytes.
 * Return: pointer to the new memory block
 */
void *_reallocf(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == old_size)
	{
		return (ptr);
	}

	new_ptr = _realloc(ptr, old_size, new_size);
	if (!new_ptr && new_size > 0)
	{
		free(ptr);
	}

	return (new_ptr);
}
/**
 * malloc - an unmallocated array
 *
 * arr: Array input
 * Return: Pointer to malloc'd array
 */
char **malloc_array(char **arr)
{
	size_t i;

	if (!arr)
	{
		return (NULL);
	}

	for (i = 0; arr[i]; i++)
	{
		arr[i] = _realloc(arr[i], strlen(arr[i]) + 1, strlen(arr[i]) + 1);
		if (!arr[i])
		{
			while (i > 0)
			{
				free(arr[--i]);
			}
			return (NULL);
		}
	}
	arr = _realloc(arr, sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
	if (!arr)
	{
		perror("malloc_array");
		return (NULL);
	}

	arr[i] = NULL;

	return (arr);
}
/**
 * _setenv - Changes or adds an environment variable
 *
 * @name: Variable name
 * @value: Variable value
 * Return: 3
 */
int _setenv(const char *name, const char *value)
{
	size_t size = strlen(name) + strlen(value) + 2;
	/**size_t start = strlen(name);*/
	size_t psize = sizeof(char *);
	int i;

	if (!environ || !name || !value || !value[0] || strchr(name, '='))
	{
		perror("_setenv");
		return (-1);
	}
	
	if (!_getenv(name))
	{
		for (i = 0; environ[i]; i++)
		{
		}
		environ = _reallocf(environ, i * psize, (i + 2) * psize);
		/**environ[i] = malloc(sizeof(char) * size);*/

		if (!environ[i])
		{
			perror("_setenv");
			return (-1);
		}
		environ[i] = malloc(sizeof(char) * size);
		if (!environ[i])
		{
			perror("_setenv");
			return (-1);
		}

		snprintf(environ[i], size, "%s=%s", name, value);
		environ[++i] = NULL;
		return (0);
	}

	if (_getenv(name) && value[0])
	{
		i = env_index(name);

		if (i < 0)
		{
			return (-1);
		}

		environ[i] =_realloc(environ[i], strlen(environ[i]) + 1,size);

		if (!environ[i])
		{
			perror("_setenv");
			return (-1);
		}

		snprintf(environ[i], size, "%s=%s", name, value);
	}
	
	return (0);
}

