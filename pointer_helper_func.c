#include "main.h"

/**
 * poinetr_function - write a an address
 * @buffer: character array
 * @index: index
 * @len: length
 * Return: number of bytes
 */

int pointer_helper_function(char buffer[], int index, int len)
{
	(void)len;

	buffer[--index] = 'x';

	buffer[--index] = '0';

	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
