#include "main.h"

/**
 * print_unsigned - print unsigned integer
 * @arg: List a of arguments
 * @buffer: Buffer array to handle print
 * Return: num( character bytes printed).
 */

int unsigned_function(va_list arg, char buffer[], int f, int w, int p)
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

	return (unsigned_printer(0, k, buffer, f, w, p));
}

/**
 * octal_function - prints an unsigned no. in octal notation
 * @arg: arguments
 * @buffer: buffer array
 * Return:  n(of character bytes printed)
 */

int octal_function(va_list arg, char buffer[], int f, int w, int p)
{
	int k = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arg, unsigned long int);
	unsigned long int flg_number = number;

	(void)width;

	if (number == 0)
		buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[k--] = (number % 8) + '0';
		number = number / 8;
	}
	k++;

	if (flags & 8 && flg_number != 0)
		buffer[k--] = '0';
	k++;

	return (unsigned_printer(0, k, buffer, f, w, p));
}

/**
 * hexadecimal_function - Prints an unsigned number
 * in hexadecimal notation
 * @arg: arguments
 * @buffer: buffer array
 * Return: n(of character bytes printed)
 */

int hexadecimal_function(va_list arg, char buffer[], int f, int w, int p)
{
	return (hexa_print(arg, "0123456789abcdef", buffer, f, 'x', w, p));
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

/**
 * pointer_printer - writes address
 * @buffer: chars array
 * @index: where number begins
 * @len: length
 * @w: width
 * @f: flags
 * @bdd: padding
 * @more_c: additional char
 * @bdd_st: where padding begins
 * Return: chars written
 */
int pointer_printer(char buffer[], int index, int len, int w, int f, char bdd, char more_c, int bdd_st)
{
	int a;

	if (w > len)
	{
		for (a = 3; a < w - len + 3; a++)
			buffer[a] = bdd;
		buffer[a] = '\0';
		if (f & 1 && bdd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';

			if (more_c)
				buffer[--index] = more_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[ind], len));
		}

		else if (!(f & 1) && bdd == '0')
		{
			if (more_c)
				buffer[--bdd_st] = more_c;
			buffer[1] = '0';
			buffer[2] = 'x';

			return (write(1, &buffer[bdd_st], a - bdd_st) + write(1, &buffer[index], len - (1 - bdd_st) - 2));
		}
	}

	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (more_c)
		buffer[--ind] = more_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

