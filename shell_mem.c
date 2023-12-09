#include "shell.h"
/**
 * string_switch - frees a string
 * @dest: address of string
 * @source: address of the string to place
 * Return: 0
 */
int switch_string(char  **dest, char **source)
{
	if (*dest == NULL || *source == NULL)
		return (1);

	free(*dest);
	*dest = _strdup(*source);

	return ((*dest == NULL) ? 1 : 0);
}

/**
 * free_string_array - frees an array
 * @str_array: address of pointer
 * Return: 0
 */
int free_string_array(char **str_array)
{
	int i;

	if (str_array == NULL)
		return (1);
	for (i = 0; str_array[i] != NULL; i++)
	{
		free(str_array[i]);
		str_array[i] = NULL;
	}

	free(str_array);

	return (0);
}
