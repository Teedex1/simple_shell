#include "shell.h"
/**
 * string_switch - frees a string
 * @dest: address of string
 * @source: address of the string to place
 * Return: 0
 */
int string_switch(char  **prev, char **tmp)
{
	free(*prev);
	*prev = NULL;

	*prev = _strdup(*tmp);
	if (!*prev)
	{
		return (1);
	}
	return (0);
}

/**
 * free_string_array - frees an array
 * @str_array: address of pointer
 * Return: 0
 */
int free_string_array(char **str_array)
{
	int i;

	if (!str_array)
		return (1);
	
	for (i = 0; str_array[i] != NULL; i++)
	{
		free(str_array[i]);

	}

	free(str_array);

	return (0);
}
