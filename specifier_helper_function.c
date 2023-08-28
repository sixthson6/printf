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
		va_list arg, char buffer[], int f, int w, int p)
{
	int i, len = 0, count = -1, holder;
	format_types function[] = {
		{'c', char_function}, {'u', unsigned_function}, {'S', nonprintable_function},
		{'s', string_function}, {'o', octal_function}, {'p', pointer_function},
		{'i', int_function}, {'x', hexadecimal_function}, {'R', rot13string_function},
		{'d', int_function}, {'X', hexadecimal_function}, {'r', reverse_function},
		{'%', percent_function}, {'b', binary_function},
		{'\0', NULL}
	};
	(void)buffer;

	for (i = 0; function[i].sym != '\0'; i++)
	{
		if (format[*index] == function[i].sym)
		{
			holder = function[i]._print(arg, buffer, f, w, p);
			return (holder);
		}
	}
	if (function[i].sym == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		len += write(1, "%%", 1);

		if (format[*index - 1] == ' ')
			len += write(1, " ", 1);
		else if (w)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		len += write(1, &format[*index], 1);
		return (len);
	}
	return (count);
}
