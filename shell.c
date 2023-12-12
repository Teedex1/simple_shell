#include "shell.h"
/**
 * path_checker - append the directory
 * @args: adrress the array
 */
void path_checker(char **args)
{
	int i;
	int cwd_index;
	char *path_env;
	char **path_tokens;
	char *cwd_path;
	char *full_path = NULL;

	cwd_index = empty_path(args[0]);

	path_env = _getenv("PATH");
	path_tokens = strtok_array(path_env, ":");
	free(path_env);

	for (i = 0; path_tokens[i]; ++i)
	{
		if (i == cwd_index)
		{
			cwd_path = cmd_cwd(args[0]);
			if (cwd_path != NULL)
			{
				string_switch(&args[0], &cwd_path);
				free(cwd_path);
				break;
			}
		}
		
		full_path = malloc(strlen(path_tokens[i]) + strlen(args[0]) + 2);

		if (full_path == NULL)
		{
			perror("Memory alloction error");
			return;
		}
		
		snprintf(full_path, strlen(path_tokens[i]) + strlen(args[0]) + 2, "%s/%s", path_tokens[i], args[0]);

		if (access(full_path, X_OK) == 0)
		{
			string_switch(&args[0], &full_path);
			free(full_path);
			break;
		}

		free(full_path);
	}
	if (!path_tokens[i])
	{
		free(full_path);
	}

	free_array(path_tokens);
}
/**
 * parent_forking - parent fork
 * @args: array
 * @shell: shell program
 * @line: line
 * Return: success
 */

int parent_forking(char **args, char *shell, int line)
{
	int child_pid, wait_status, exitcode = 0;
	struct stat st;

	if (!args)
		return (0);

	if (stat(args[0], &st) == -1 || access(args[0], X_OK) == -1)
		path_checker(args);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (stat(args[0], &st) == -1 || access(args[0], X_OK) == -1)
		{
			print_command_not_found_error(args[0], shell, line);
			exit(127);
		}

		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			exit(127);
		}
	}
	
	else
	{
		wait_status = 0;
		waitpid(child_pid, &wait_status, 0);

		if (WIFEXITED(wait_status))
		{
			exitcode = WEXITSTATUS(wait_status);
		}
		else if (WIFSIGNALED(wait_status))
		{
			fprintf(stderr, "Child process terminated due to signal %d\n", WTERMSIG(wait_status));
		}
		
		else
		{
			fprintf(stderr, "Child process terminated unexpectedly\n");
			exitcode = -1;
		}
	}
	return (exitcode);
}
/**
 * word_counter - counts the number of words in a string
 * @str: string
 * @del: delimiter
 * Return: 0
 */
int word_counter(const char *str, const char *del)
{
	int wordcounter = 0;
	char *sdup, *token, *saveptr;

	sdup = strdup(str);
	if (!sdup)
		return (0);

	token = strtok_r(sdup, del, &saveptr);

	while (token)
	{
		wordcounter++;
		token = strtok_r(NULL, del, &saveptr);
	}

	free(sdup);
	
	return (wordcounter);
}
/**
 * strtok_arr - splits a string
 * @str: string
 * @del: delimiter
 * Return: NULL
 */
char **strtok_array(const char *str, const char *del)
{
	char **arr;
	char **tmp;
	size_t i;
	char *token;
	size_t j;
	char *dup;

	if (!str || !str[0])
		return (NULL);

	arr = malloc(sizeof(char *));
	if (!arr)
		return (NULL);

	dup = strdup(str);
	
	if (!dup)
	{
		free(arr);
		return (NULL);
	}
	
	i = 0;

	token = strtok(dup, del);
	while (token)
	{
		arr[i] = strdup(token);
		if (!arr[i])
		{
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
			free(dup);
			return (NULL);
		}

		token = strtok(NULL, del);
		i++;

		tmp = realloc(arr, (i + 1) * sizeof(char *));
		if (!tmp)
		{
			free(arr[i - 1]);
			free(arr);
			free(dup);

			return (NULL);
		}

		arr = tmp;
	}
	
	arr[i] = NULL;

	free(dup);

	return (arr);
}
/**
 * _getline - Read a line
 * @shell: Name of shell
 * Return: 0
 */
int _getline(char *shell)
{
	size_t len = 0;
	ssize_t getlen;
	char *buf = NULL, **args = NULL;
	int check_exits, code_exits = 0, line = 1, errcode = 0;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		getlen = getline(&buf, &len, stdin);

		if (getlen == -1)
			break;

		if (buf[getlen -1] == '\n')
			buf[getlen - 1] = '\0';

		args = strtok_array(buf, " ");

		check_exits = builtin_checker(args, shell, &errcode);

		if (args) {
			free_array(args);
			args = NULL;
		}

		if (check_exits == 2)
		{
			check_exits = atoll(args[1]);
			/**free_array(args);*/
			/**free_array(environ);*/
			if (buf)
			{
				free(buf);
				buf = NULL;
			}
			return (code_exits);
		}

		if (code_exits == 0)
		{
			errcode = parent_forking(args, shell, line);
		}

		free_array(args);

		if (check_exits == 1)
		{
			break;
		}
		
		if (!isatty(STDIN_FILENO))
		{
			line++;
		}
	}
	
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	
	free_array(environ);

	if (isatty(STDIN_FILENO) && check_exits != 1)
	{
		write(STDOUT_FILENO, "\n", 1);
	}

	return (errcode);
}
/**
 * free_array - free the array
 * @arr: array pointer
 * Return: 0
 */
void free_array(char **arr)
{
	size_t i;

	if (arr)
	{
		for (i = 0; arr[i]; i++)
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		free(arr);
	}
}
