#include "main.h"
#include <stdio.h>

/**
 * char_function - prints a character
 * @arg: list of arguments
 * @buffer: allocation to handele print
 * Return: 0
 */
int char_function(va_list arg, char buffer[], int f, int w, int p)
{
	char a = va_arg(arg, int);

	(void)f;
	(void)w;
	(void)p;

	return (write_function(a, buffer, f, w, p));
}

/**
 * string_function - prints a string
 * @arg: list of arguments
 * @buffer: allocation to handle print
 * Return: number of bytes printed
 */
int string_function(va_list arg, char buffer[], int f, int w, int p)
{
	int len = 0;
	char *str = va_arg(arg, char *);

	(void)buffer;
	(void)f;
	(void)w;
	(void)p;

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
 * @buffer: temporal storage
 * Return: number of bytes
 */
int percent_function(va_list arg, char buffer[], int f, int w, int p)
{
	(void)arg;
	(void)buffer;
	(void)f;
	(void)w;
	(void)p;

	return (write(1, "%%", 1));
}

/**
 * int_function - prints int
 * @arg: list of arguments
 * @buffer: temporal storage
 * Return: number of bytes printed
 */
int int_function(va_list arg, char buffer[], int f, int w, int p)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int y = va_arg(arg, long int);
	unsigned long int num;

	/*y = size_number_function(y, size);*/

	if (y == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)y;

	if (y < 0)
	{
		num = (unsigned long int)((-1) * y);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_number_function(is_negative, x, buffer, f, w, p));
}

/**
 * binary_function - prints unsigned
 * @arg: arguments
 * @buffer: temporary location
 */
int binary_function(va_list arg, char buffer[], int f, int w, int p)
{
	unsigned int a, b, c, sum;
	unsigned int n[32];
	int count;
	char d;

	(void)buffer;
	(void)f;
	(void)w;
	(void)p;

	a = va_arg(arg, unsigned int);
	b = 2147483648;
	n[0] = a / b;
	for (c = 1; c < 32; c++)
	{
		b /= 2;
		n[c] = (a / b) % 2;
	}
	for (c = 0, sum = 0, count = 0; c < 32; c++)
	{
		sum += n[c];
		if (sum || c == 32)
		{
			d = '0' + n[c];

			write(1, &d, 1);
			count++;
		}
	}
	return (count);
}
