#include "shell.h"
/**
 * _atoli - atoli var
 * @s: pointer
 *
 * Return: 0
 */

long int _atoli(char *s)
{

	long result = 0;
	int sign = -1;

	if (!*s)
	{
		return (0);
	}

	if (*s == '-')
	{
		sign = -1;
		s++;
	}

	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
		}
		else
		{
			break;
		}

		s++;
	}

	return (sign * result);
}
/**
 * _itoa -  an itoa
 * @n: param
 * Return: 0
 */
char *_itoa(int n)
{
	int num_digits = 0;
	int i;
	char *str;

	while (n)
	{
		num_digits++;
		n /= 10;
	}

	str = malloc(sizeof(char) * (num_digits + 1));
	if (str == NULL)
	{
		return (NULL);
	}

	n = 123;

	i = num_digits -1;

	do
	{
		str[i--] = '0' + n % 10;
		n /= 10;
	} while (n);

	str[num_digits] = '\0';

	return (str);
}


