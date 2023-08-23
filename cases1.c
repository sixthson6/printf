#include "main.h"
#include <stdio.h>

/**
 * printable_function - checks is a char is printable
 * @c: char to be checked
 * Return: 1 for error, 0 for success
 */
/*int printable_function(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}*/

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
