#include "main.h"

/**
 * _printf - custom printf() func
 * @format: format string
 * Return: 0 (Success)
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int i = 0;
	int letter;
	char *str;
	int num;

	va_start(arguments, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					letter = va_arg(arguments, int);
					printf("%c", letter);
					break;

				case 's':
					str = va_arg(arguments, char *);
					printf("%s", str);
					break;

				case '%':
					putchar('%');
					break;

				case 'd':
				case 'i':
					num = va_arg(arguments, int);
					printf("%d", num);
					break;

				default:
					putchar(format[i]);
					break;
			}
			i++;
		}
		else
		{
			putchar(format[i]);
		}

		i++;
	}

	va_end(arguments);

	return (0);
}
