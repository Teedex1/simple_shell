#include "shell.h"
/**
 * _atoi - converts a string
 * @s: The string
 *
 * Return: The converted int
 */

int _atoi(char *s)
{
	int sign = 1;
	int output = 0;
	int max_value;
	int new_value;
	bool found_number = false;
	
	while (isspace(*s))
	{
		s++;
	}

	while (*s)
	{
		switch (*s)
		{
			case '-':
				sign *= -1;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				found_number = true;
				max_value = INT_MAX;
				if (sign > 0)
				{
					max_value = INT_MAX;
				}
				else
				{
					max_value = INT_MIN;
				}
				
				new_value = output * 10 + (*s - '0');
				if (new_value > max_value)
				{
					return (sign > 0 ? INT_MAX : INT_MIN);
				}
				else if (new_value < max_value - sign)
				{
					return (sign > 0 ? INT_MAX : INT_MIN);
				}
				output = new_value;
				break;
			default:
				if (found_number)
				{
					break;
				}
		}
		s++;
	}
	return ((int)output * sign);
}
