#include "main.h"
#include <stdio.h>

/**
 * char_function - prints a character
 * @arg: list of arguments
 * @buffer: allocation to handele print
 * Return: 0
 */
int char_function(va_list arg, char buffer[])
{
	char a = va_arg(arg, int);

	return (write_function(a, buffer));
}

/**
 * string_function - prints a string
 * @arg: list of arguments
 * @buffer: allocation to handle print
 * Return: number of bytes printed
 */
int string_function(va_list arg, char buffer[])
{
	int len = 0;
	char *str = va_arg(arg, char *);

	(void)buffer;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[len] != '\0')
		len++;


	return (write(1, str, len));
}

/**
 * percent_function - prints percent sign
 * @arg: list of arguments
 * Return: number of bytes printed
 */
int percent_function(va_arg arg, char buffer[])
{
	(void)arg;
	(void)buffer;

	return (write(1, "%%", 1));
}

/**
 * int_function - prints int
 * @arg: list of arguments
 * Return: number of bytes printed
 */
int int_function(va_list arg, char buffer[])
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int y = va_arg(arg, long int);
	unsigned long int num;

/*	y = size_number_function(y, size);*/

	if (y == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)y;

	if (y < 0)
	{
		num = (unsigned long int)((-1) *y);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_number_function(is_negative, i, buffer));
}
