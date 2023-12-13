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
char *_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	if (!dest || !src)
	{
		return (dest);
	}

	while (*src)
	{
		*dest++ = *src++;
	}

	*dest = '\0';

	return (original_dest);
}

/**
 * str_concat - creats a copy
 * @s1: string 1
 * @s2: string 2
 * Return: 0
 */
char *str_concat(char *s1, char *s2)
{

	char *new_str;

	size_t len1 = (s1) ? _strlen(s1) : 0;
	size_t len2 = (s2) ? _strlen(s2) : 0;
	size_t total_len = len1 + len2 + 1;
	
	new_str = malloc(total_len);

	if (!new_str)
	{
		return (NULL);
	}

	if (s1)
	{
		strcpy(new_str, s1);
	}

	if (s2)
	{
		strcat(new_str, s2);
	}

	return (new_str);
}
/**
 * _strcmp - compare strings
 * @s1: string
 * @s2: stirng
 * Return: 0
 */
int custom_strcmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 && !s2)
	{
		return (0);
	}
	
	if (!s1 || !s2)
	{
		return (-1);
	}

	while (n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}

	return (n == 0) ? 0 : (*s1 - *s2);
}
size_t array_length(char **arr)
{
	size_t length = 0;
	while (arr[length] != NULL)
	{
		length++;
	}
	return (length);
}
