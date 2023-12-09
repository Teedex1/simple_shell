#include "shell.h"
/**
 * custom_custom_builtin - checks whether custom bultin function called
 * @args: array of arguments passed to the shell
 * @shell_name: name of shell
 * @command_line: line number
 * @error_code: address of error
 * Return: 0
 */
int check_custom_builtin(char **args, char *shell_name, int command_line, int *error_code)
{
	int i;
	/**char *command = args[0]; */
	char *endptr;
	long int number;

	if (!args || !args[0])
	{
		return (3);
	}
	
	if (!strcmp(args[0], "custom_setenv"))
	{
		if (!args[1] || !args[2])
		{
			*error_code = 2;
			custom_perror_exit(args[0], shell_name, command_line);
			return (3);
		}
		if (custom_setenv(strdup(args[1]), strdup(args[2])) == -1)
		{
			*error_code = 2;
			custom_perror_exit(args[0], shell_name, command_line);
			return (3);
		}
		return (2);
	}
	else if (!strcmp(args[0], "custom_unsetenv"))
	{
		if (!args[1])
		{
			*error_code = 2;
			custom_perror_exit(args[0], shell_name, command_line);
			return (3);
		}
		
		else if (custom_unsetenv(args[1]) == -1)
		{
			*error_code = 2;
			custom_perror_exit(args[0], shell_name, command_line);
			return (3);
		}
		
		return (2);
	}
	
	else if (!strcmp(args[0], "custom_env"))
	{
		return (_printenv());
	}
	else if (!strcmp(args[0], "custom_exit"))
	{
		if (args[1])
		{
			number = strtoll(args[1], &endptr, 10);
			if(*endptr != '\0' || number < INT_MIN || number > INT_MAX)
			{
				*error_code = 2;
				custom_perror_exit(args[0], shell_name, command_line);
				return (3);
			}
			*error_code = (int)number;
		}
		return (0);
	}
	else
	{
		if (!args[1])
		{
			return (1);
		}
		
		for (i = 0; args[1][i]; i++)
		{
			if (!isdigit(args[1][i]))
			{
				*error_code = 2;
				custom_perror_exit(args[1], shell_name, command_line);
				return (3);
			}
		}
		
		number = strtoll(args[1], &endptr, 10);
		
		if (*endptr != '\0' || number > INT_MAX)
		{
			*error_code = 2;
			custom_perror_exit(args[1], shell_name, command_line);
			return (3);
		}
		return (2);
	}
}

/**
 * custom_perror_exit - prints an error message and exits
 * @arg: arugment
 * @shell: shell
 * @line: line
 * Return: 0
 */
void custom_perror_exit(char *arg, char *shell, int line)
{
	char str_line[MAX_CONVERSION_BUFFER];
	char *tmp1, *tmp2;

	tmp1 = str_concat(shell, ": ");
	snprintf(str_line, sizeof(str_line), "%ld",(long)line);
	tmp2 = str_concat(tmp1, str_line);
	free(tmp1);
	tmp1 = str_concat(tmp2, ": exit: ");
	free(tmp2);
	tmp2 = str_concat(tmp1, arg);
	free(tmp1);
	tmp1 = str_concat(tmp2, "\n");
	free(tmp2);
	fprintf(stderr, "%s", tmp1);
	free(tmp1);
	exit(1);
}
