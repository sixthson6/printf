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
