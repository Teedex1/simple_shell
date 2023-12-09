#include "shell.h"
/**
 * cmd_cwd - appends the cmd string to the current directory
 * @cmd: first string
 * Return: NULL
 */
char *cmd_cwd(char *cmd)
{
	size_t size = 120;
	char *buf, *cwd;
	struct stat st;

	if (!cmd)
		return (NULL);

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	
	size += _strlen(cmd) + _strlen(cwd) + 2;
	buf = malloc(sizeof(char) * size);
	if (!buf)
	{
		free(cwd);
		return (NULL);
	}
	
	snprintf(buf, size, "%s/%s", cwd, cmd);

	free(cwd);

	if (stat(buf, &st) == 0)
		return (buf);
	
	free(buf);
	return (NULL);
}

/**
 * cmd_path - appends the cmd string to a directory
 * @cmd: first string
 * @path: single path
 * Return: NULL
 */

char *cmd_path(char *cmd, char *path)
{
	size_t size;
	char *buf;
	struct stat st;

	if (!cmd || !path)
		return (NULL);

	if (!path[0])
		return (NULL);

	size = _strlen(cmd) + _strlen(path) + 2;
	buf = malloc(sizeof(char) * size);
	if (!buf)
		return (NULL);

	snprintf(buf, size, "%s/%s", path, cmd);


	if (stat(buf, &st) == 0)
		return (buf);

	free(buf);
	return (NULL);
}
/**
 * slash_sps - check whether the argument constains a slash
 * @str: string
 * Return: 0
 */
int slash_sps(char *str)
{
	int count = 0;

	if (!str)
		return (0);

	while (*str)
	{
		if (*str++ == '/')
			count++;
	}

	return (count);
}
/**
 * empty_path - checks the path
 * @path: string
 * Return: -1
 */
int empty_path(char *path)
{
	int index = 0;

	if (!path)
		return (-1);

	while (*path)
	{
		if (path[0] == ':' && path[1] == ':')
			return (index);
		if (*path == ':' && (path[1] == 0 || path[1] == ':'))
			index++;
		path++;
	}
	
	return (-1);
}
