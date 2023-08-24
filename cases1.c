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
		if (print_printable_func(strr[i]))
			buffer[i + off] = strr[i];
		else
			off += hexa_convert(strr[i], buffer, i + off);
		i++;
	}

	buffer[i + off] = '\0';

	return (write(1, buffer, i + off));
}

/**
 * pointer_function - prints value of a pointer variable
 * @arg: list of arguments
 * @buffer: array for print
 */
int pointer_function(va_list arg, char buffer[])
{
	int nd = BUFF_SIZE - 2, len =2, paddd_st = 1;
	unsigned long num_add;
	char mp_to[] = "0123456789abcdef";
	void *adddrs = va_arg(arg, void *);

	buffer[BUFF_SIZE - 1] = '\0';

	num_add = (unsigned long)adddrs;

	while (num_add > 0)
	{
		buffer[nd--] = map_to[num_adddrs % 16];
		num_adddrs /= 16;
		len;
	}

	return (pointer_helper_function(buffer, nd, len));
}

