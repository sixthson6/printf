#include "main.h"

/**
 * write_function - Print string
 * @c: char
 * @buffer: temp storage
 * Return: no. of bytes printed
 */

int write_function(char c, char buffer[], int f, int w, int p)
{
	int k = 0;
	/*char separator = ' ';*/
	(void)f;
	(void)w;
	(void)p;

	buffer[k++] = c;
	buffer[k] = '\0';

	return (write(1, &buffer[0], 1));
}

/**
 * write_number_function - prints string
 * @is_neg: arguments
 * @index: char types
 * @buffer: buffer array to handle print
 * Return: no of chars printed
 */

int write_number_function(int is_neg, int index, char buffer[], int f, int w, int p)
{
	int len = BUFF_SIZE - index - 1;

	(void)is_neg;
	(void)f;
	(void)w;
	(void)p;

	return (write_num(index, buffer, len, f, w, p));
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
