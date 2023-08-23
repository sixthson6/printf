#include "main.h"

/**
 * _printf - custom printf() function
 * @format: format string
 * Return: Number of bytes to the stdout
 */

int _printf(const char *format, ...)
{
	int i, specifiers_printed = 0, chars_printed = 0;
	int buffer_index = 0;
	char buffer[BUFF_SIZE];
	va_list arg;

	if (format == NULL)
		return (-1);

	va_start(arg, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index] = format[i];
			buffer_index++;

			if (buffer_index == BUFF_SIZE)
				buffer_printer(buffer, &buffer_index);

			chars_printed++;
		}

		else
		{
			buffer_printer(buffer, &buffer_index);
			++i;
			specifiers_printed = specifier_print_function(format, &i, list);

			if (specifiers_printed == -1)
				return (-1);
			chars_printed += specifiers_printed;
		}
	}

	buffer_printer(buffer, &buffer_index);

	va_end(list);

	return (chars_printed);
}

/**
 * buffer_printer - prints string in buffer
 * @buffer: char array
 * @buffer_index: count
 * Return: Nothing
 */

void buffer_printer(char buffer[], *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buff_ind);

	*buffer_index = 0;
}
