#include "main.h"

/**
 * _printf - custom printf() func
 * @format: format string
 * Return: 0 (Success)
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int count = 0;
	int letter;
	char *str;

	va_start(arguments, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					letter = (char)va_arg(arguments, int);
					putchar(letter);
					count++;
					break;

				case 's':
					str = va_arg(arguments, char *);
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
					break;

				case '%':
					putchar('%');
					count++;
					break;


				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(arguments);

	return (0);
}
