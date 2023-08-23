#include "main.h"

/**
 * print_unsigned - print unsigned integer
 * @arg: List a of arguments
 * @buffer: Buffer array to handle print
 * Return: num( character bytes printed).
 */

int unsigned_function(va_list arg, char buffer[])
{
	int k = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arg, unsigned long int);

	if (number == 0)
	{
		buffer[k--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[k--] = (number % 10) + '0';
		number = number / 10;
	}
	k++;

	return (unsigned_printer(0, k, buffer));
}

/**
 * octal_function - prints an unsigned no. in octal notation
 * @arg: arguments
 * @buffer: buffer array
 * Return:  n(of character bytes printed)
 */

int octal_function(va_list arg, char buffer[])
{
	int k = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arg, unsigned long int);

	if (number == 0)
		buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[k--] = (number % 8) + '0';
		number = number / 8;
	}
	k++;

	return (unsigned_printer(0, k, buffer));
}

/**
 * hexadecimal_function - Prints an unsigned number 
 * in hexadecimal notation
 * @arg: arguments
 * @buffer: buffer array
 * Return: n(of character bytes printed)
 */

int hexadecimal_function(va_list arg, char buffer[])
{
	return (hexa_print(arg, "0123456789abcdef", buffer));
}

/**
 * hexa_print - Prints a hexa num
 * @types: arguments
 * @map: Array of values to map the number to
 * @buffer: buffer array
 * Return: n(of character bytes printed)
 */

int hexa_print(va_list arg, char map[], char buffer[])
{
	int k = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arg, unsigned long int);

	(void)map;

	if (number == 0)
		buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[k--] = map[number % 16];
		number = number / 16;
	}
	k++;
	return (unsigned_printer(0, k, buffer));
}
