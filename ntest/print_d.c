#include "main.h"

/**
 * printNumber - print num
 * @num: number
 * Return: Nothing
 */

void printNumber(int num)
{
	int revNum, digit;

	if (num < 0)
	{
		putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		putchar('0');
		return;
	}

	revNum = 0;

	while (num > 0)
	{
		digit = num % 10;
		revNum = revNum * 10 + digit;
		num /= 10;
	}

	while (revNum > 0)
	{
		digit = revNum % 10;
		putchar('0' + digit);
		revNum /= 10;
	}
}


/**
 * _printf - custom printf()
 * @format: format string
 * Return: 0 (Success);
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int count = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(arguments, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += handle_format_argument(&format, arguments);
		}

		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(arguments);

	return (count);
}

/**
 * handle_format_argument - handles the format argument
 * @format: format string
 * @arguments: va_list of arguments
 * Return: Number of characters printed
 */
int handle_format_argument(const char **format, va_list arguments)
{
	int count = 0;
	int num;

	switch (**format)
	{
		case 'd':
		case 'i':
			num = va_arg(arguments, int);
			printNumber(num);
			count++;
			break;

		default:
			putchar('%');
			putchar(**format);
			count += 2;
			break;
	}
	return (count);
}
