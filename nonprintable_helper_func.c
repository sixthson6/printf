#include "main.h"

/**
 * print_printable_func - prints chars that is printable
 * @n: character
 * Return: 1 (printable), 0 (non_printable)
 */
int print_printable_func(char n)
{
	if (n >= 32 && n < 127)
		return (1);
	return (0);
}

/**
 * hexa_convert - substitute ascii version in hexadecimal code to buffer
 * @buffer: char array
 * @i: Index
 * @ascii_c: ASSCI CODE.
 * Return: Always 3 (no. of bytes)
 */
int hexa_convert(char ascii_c, char buffer[], int i)
{
	char hexa_map[] = "0123456789ABCDEF";

	if (ascii_c < 0)
		ascii_c = ascii_c * -1;

	buffer[i++] = '\\';

	buffer[i++] = 'x';

	buffer[i++] = hexa_map[ascii_c / 16];

	buffer[i] = hexa_map[ascii_c % 16];

	return (3);
}

