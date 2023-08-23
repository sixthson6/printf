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
		{'c', char_fucntion},
		{'s', string_function},
		{'i', int_fucntion},
		{'d', int_fucntion},
		{'%', percentage_function},
		{'\0', NULL}
	};

	for (i = 0; functon[i].format != '\0'; i++)
	{
		if (format[*index] == format_types[i].sym)
		{
			holder = format_types[i]._print(arg, buffer);
			return (holder);
		}
	}

	if (format_types[i].sym == '\0')
	{
		if (format[index] == '\0')
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
