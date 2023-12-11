#include "shell.h"
/**
 * custom_custom_builtin - checks whether custom bultin function called
 * @args: array of arguments passed to the shell
 * @shell_name: name of shell
 * @command_line: line number
 * @error_code: address of error
 * Return: 0
 */
int builtin_checker(char **args, char *shell, int *errcode)
{
	int i;
	long int exit_code;
	char error_msg[1024];

	if (!args || !args[0])
	{
		return (3);
	}
	if (strcmp(args[0], "setenv") == 0)
	{
		if (!args[1] || _setenv(args[1], args[2]) == -1)
		{
			perror("setenv");
			return (3);
		}
		return (2);
	}

	if (strcmp(args[0], "unsetenv") == 0)
	{
		if (!args[1] || _unsetenv(args[1]) == -1)
		{
			perror("unsetenv");
			return (3);
		}
		return (2);
	}
	if (strcmp(args[0], "env") == 0)
	{
		return _printenv();
	}
	if (strcmp(args[0], "exit") == 0)
	{
		if (!args[1])
		{
			return(1);
		}
		
		for (i = 0; args[1][i]; ++i)
		{
			if (!isdigit(args[1][i]) || i > 9)
			{
				snprintf(error_msg, sizeof(error_msg), "%s: exit: Illegal number: %s", shell, args[1]);
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		*errcode = 2;
		return (3);
			}
		}
		
		exit_code = strtol(args[1], NULL, 10);
		if (exit_code > INT_MAX)
		{
			snprintf(error_msg, sizeof(error_msg), "%s: exit: Number too large: %s", shell, args[1]);
			write(STDERR_FILENO, error_msg, strlen(error_msg));
			*errcode = 2;
			return (3);
		}
		return (2);
	}
	return (0);
}

