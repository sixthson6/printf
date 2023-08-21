#include "main.h"

/**
 * print_str - print string
 * @str: string
 * Return: Nothing
 */

void print_str(char *str)
{
	if (str == NULL)
		return;

	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}

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
	int letter;
	char *str;
	int count = 0;
	int num;

	va_start(arguments, format);

	while (*format != '\0')
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
					print_str(str);
					count++;
					break;
				case '%':
					putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					num = va_arg(arguments, int);
					printNumber(num);
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

	return (count);
}
