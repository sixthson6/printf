#include "main.h"

/**
 * flag_function - turns on flags for printf
 * @format: format string
 * @i: takes parameter
 * Return: flags
 */
int flag_function(const char *format, int *i)
{
	int k, current_i, f = 0;
	const char array_1[] = {'-', '+', '0', '#', ' ', '\0'};
	const int array_2[] = {1, 2, 4, 8, 16, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (k = 0; array_1[k] !='\0'; k++)
			if (format[current_i] == array_1[k])
			{
				f |= array_2[k];
				break;
			}
		if (array_1[k] == 0)
			break;
	}
	*i = current_i - 1;

	return (f);
}

/**
 * precision_function - precision for printing
 * @format: string
 * @i: arguments
 * @arg: arguments
 * Return: precision
 */
int precision_function(const char *format, int *i, va_list list)
{
	int current_i = *i + 1;
	int p = -1;

	if (format[current_i] != '.')
		return (p);
	p = 0;

	for (current_i += 1; format[current_i] != '\0'; current_i++)
	{
		if (digit_function(format[current_i]))
		{
			p *= 10;
			p += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			p = va_arg(arg, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = current_i - 1;

	return (p);
}

/**
 * width_function - calculates
 * @format: format string
 * @i: arguments
 * @arg: arguments
 * Return: width
 */
int width_function(const char *format, int *i, va_list arg)
{
	int current_i;
	int w = 0;

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		if (digit_function(format[current_i]))
		{
			w = w * 10;
			w = w + format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			w = va_arg(arg, int);
			break;
		}
		else
		{
			break;
		}
	}
	
	*i = current_i - 1;

	return (w);

}

/**
 * digit_function - checks for digit
 * @c: char
 * Return: 0 or 1
 */
int digit_function(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);

}
