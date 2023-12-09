#include "shell.h"
/**
 * _strlen - gives the length
 * @str: string
 * Return: num of char
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}
/**
 * _strdup - creates and return a pointer
 * @str: string
 * Return: NUll
 */
char *_strdup(const char *str)
{
	size_t len;
	char *new_str;

	if (!str)
	{
		return (NULL);
	}

	len = _strlen(str) + 1;
	new_str = malloc(len);

	if (!new_str)
	{
		return (NULL);
	}
	strcpy(new_str, str);

	return (new_str);
}
/**
 * _strcpy - copies string
 * @dest: variable
 * @src: soruce
 * Return: pointer dest
 */
char *_strcpy(char *dest, char *src)
{
	if (!dest || !src)
	{
		return (dest);
	}

	/**char *original_dest = dest;*/

	while (*src)
	{
		*dest++ = *src++;
	}

	*dest = '\0';
	return (dest);
}

/**
 * str_concat - creats a copy
 * @s1: string 1
 * @s2: string 2
 * Return: 0
 */
char *str_concat(char *s1, char *s2)
{
	size_t len1, len2, total_len;
	char *new_str;

	if (!s1 && !s2)
	{
		return (NULL);
	}

	len1 = (s1) ? _strlen(s1) : 0;
	len2 = (s2) ? _strlen(s2) : 0;
	total_len = len1 + len2 + 1;
	
	new_str = malloc(total_len);

	if (!new_str)
	{
		return (NULL);
	}

	strncpy(new_str, s1, len1);
	strncat(new_str, s2, len2);
	new_str[total_len - 1] = '\0';

	return (new_str);
}
/**
 * _strcmp - compare strings
 * @s1: string
 * @s2: stirng
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
	{
		return (-1);
	}

	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}

	return (*s1) - (*s2);
}
