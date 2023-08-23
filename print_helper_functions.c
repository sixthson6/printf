#include "main.h"

/**
 * write_function - Print string
 * @c: char
 * @buffer: temp storage
 * Return: no. of bytes printed
 */

int write_fucntion(char c, char buffer[])
{
	int k = 0;
	char separator = ' ';

	buffer[i++] = c;
	buffer[i] = '\0';

	return (write(1, &buffer[0], 1));
}

/**
 * write_number_function - prints string
 * @is_neg: arguments
 * @index: char types
 * @buffer: buffer array to handle print
 * Return: no of chars printed
 */

int write_number_function(int is_neg, int index, char buffer[])
{
	int len = BUFF_SIZE - index - 1;

	return (write_num(index, buffer, len));
}

/**
 * write_num - write num using buffer
 * @index: index
 * @buffer: buffer
 * @len: length
 * Return: number of chars printed
 */

int write_num(int index, char buffer[], int len)
{
	return (write(1, &buffer[index], len));
}
