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
	char *error_message = NULL;
	int len_shell = _strlen(shell_name);
	int len_arg = _strlen(argument);
	int len_line = _numlen(line_number);

	int total_len = len_shell + 2 + len_line + len_arg + 1;

	error_message = malloc(total_len);
	if (error_message == NULL)
	{
		return (NULL);
	}
	sprintf(error_message, "%s:%d: %s: ", shell_name, line_number, argument);

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
	char *error_message = generate_error_message(argument, shell_name, line_number);
	char *not_found_message = ": not found\n";
	char *full_message = str_concat(error_message, not_found_message);

	if (error_message == NULL)
		return (1);
	
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

size_t _numlen(int num)
{
	size_t len = 1;

	if (num < 0)
	{
		len++;
		num = -num;
	}

	while (num >= 10)
	{
		len++;
		num /= 10;
	}
	return (len);
}
