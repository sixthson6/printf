#include "main.h"

/**
 * char_fun - print char
 * @arg: argument
 * Return: Nothing
 */

void char_fun(va_list arg)
{
	int letter;

	letter = va_arg(arg, int);
	putchar((char)letter);
}

/**
 * int_fun - print int
 * @arg: argument
 * Return: Nothing
 */

void int_fun(va_list arg)
{
	int num, digit, revNum;

	num = va_arg(arg, int);

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
 * str_fun - print string
 * @arg: argument
 * Return: Nothing
 */

void str_fun(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		return;

	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}

/**
 * pr_str - percentage
 * @arg: argument
 * Return: Nothing
 */

/*void pr_str(va_list arg)
{
	int letter;

	letter = (char)va_arg(arg, int);
	putchar('%');
}*/

/**
 * _printf - custom printf
 * @format: format string
 * Return: 0 (Success)
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int i = 0, j = 0;
	print_funct functions[] = {
		{"%c", char_fun},
		{"%s", str_fun},
		{"%d", int_fun},
		{"%i", int_fun},
		/*{"%%", pr_fun}*/
	};

	va_start(arg, format);

	while (format && (*(format + i)))
	{
		j = 0;

		while (j < 4 && (*(format + i) != *(functions[j].sym)))
		{
			j++;
		}

		if (j < 4)
		{
			functions[j]._print(arg);
		}
		i++;
	}
	putchar('\n');
	va_end(arg);

	return (0);
}
