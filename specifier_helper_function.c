#include "main.h"

/**
 * specifier_print_function - helper fucntion to call argument based
 * on the conversion specifier
 * @format: format string
 * @index: index
 * @arg: argument list
 * @buffer: temp storage
 * Return: 1 or 2
 */

int specifier_print_function(const char *format, int *index,
		va_list arg, char buffer[])
{
	int i, len = 0, count = -1, holder;
	format_types function[] = {
		{'c', char_function},
		{'s', string_function},
		{'i', int_function},
		{'d', int_function},
		{'%', percent_function},
		{'\0', NULL}
	};

	(void)buffer;

	for (i = 0; function[i].sym != '\0'; i++)
	{
		if (format[*index] == function[i].sym)
		{
			holder = function[i]._print(arg, buffer);
			return (holder);
		}
	}

	if (function[i].sym == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		len += write(1, "%%", 1);

		if (format[*index - 1] == ' ')
		{
			len += write(1, " ", 1);
		}
		len += write(1, &format[*index], 1);

		return (len);
	}

	return (count);
}
