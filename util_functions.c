#include "shell.h"
/**
 * gen_error - generates error message
 * @argument: argument string
 * @shell_name: name of shell executable
 * @line_number: line command
 * Return: NULL
 */
char *generate_error_message(char *argument, char *shell_name, int line_number)
{
	char *error_message;
	int len_shell, len_arg, len_line, total_len;

	if (!argument || !shell_name)
	{
		return (NULL);
	}


	len_shell = _strlen(shell_name);
	len_arg = _strlen(argument);
	len_line = _numlen(line_number);
	
	total_len = len_shell + 2 + len_line + len_arg + 1;

	error_message = malloc(total_len);

	if (error_message == NULL)
	{
		return (NULL);
	}
	
	snprintf(error_message, total_len, "%s:%d: %s: ", shell_name, line_number, argument);

	return (error_message);
}

/**
 * print_command_not_found_error - prints an error message
 * @arg: arg string
 * @shell_name: name of shell
 * @line_number: line number
 * Return: 0
 */
int print_command_not_found_error(char *argument, char *shell_name, int line_number)
{
	char *error_message;
	char *not_found_message;
	char *full_message;

	error_message = generate_error_message(argument, shell_name, line_number);

	if (error_message == NULL)
		return (1);

	not_found_message = ": not found\n";
	full_message = str_concat(error_message, not_found_message);

	if (full_message == NULL)
	{
		free(error_message);
		return (1);
	}

	write(STDERR_FILENO, full_message, _strlen(full_message));

	free(error_message);
	free(full_message);

	return (0);
}
/**
 * _numlen - number length
 * @num: num
 * Return: 0
 */
size_t _numlen(int num)
{
	size_t len = 1;

	if (num < 0)
	{
		len++;
		num = -num;
	}

	while (num >= 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
