#include "main.h"

/**
 * get_precision - Calculates the precision for print
 * @format: Formatted string in which to print the argument
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_r = *i + 1;
	int precision = -1;

	if (format[curr_r] != '.')
		return (precision);

	precision = 0;

	for (curr_r += 1; format[curr_r] != '\0'; curr_r++)
	{
		if (is_digit(format[curr_r]))
		{
			precision *= 10;
			precision += format[curr_r] - '0';
		}
		else if (format[curr_r] == '*')
		{
			curr_r++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_r - 1;

	return (precision);
}

