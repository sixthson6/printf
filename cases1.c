#include "main.h"
#include <stdio.h>

/**
 * size_number_function - joins a number to a specified size
 * @num: number
 * @size: type
 * Return: result
 */
long int size_number_function(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * nonprintable_function - Prints ascii in hexa
 * @arg: list of arguments
 * @buffer: temporal location
 * Return: number of bytes
 */
int nonprintable_function(va_list arg, char buffer[])
{
	int i = 0, off = 0;
	char *strr = va_arg(arg, char *);

	if (strr == NULL)
		return (write(1, "(null)", 6));

	while (strr[i] != '\0')
	{
		if (print_printable_char(str[i]))
			buffer[i + off] = str[i];
		else
			off += hexa_convert(str[i], buffer, i + off);
		i++;
	}

	buffer[i + off] = '\0';

	return (write(1, buffer, i + off));
}
