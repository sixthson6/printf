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
	char sep = ' '; int c = 0;

	if ((f & 4) && !(f & 1))
	{
		sep = '0';
	}
	if (is_neg)
		c = '-';
	else if (f & 2)
		c = '+';
	else if (f & 16)
		c = ' ';

	return (write_num(index, buffer, len, f, w, p, sep, c ));
}

/**
 * write_num - write num using buffer
 * @index: index
 * @buffer: buffer
 * @len: length
 * Return: number of chars printed
 */

int write_num(int index, char buffer[], int len, int f, int w, int p, char bdd, char more_c)
{
	int a, bdd_st = 1;

	if (p == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && w == '0')
		return (0);
	if (p == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = bdd = ' ';
	if (p > 0 && p < len)
		bdd = ' ';
	while (p > len)
	{
		buffer[--index] = '0';
		len++;
	}
	if (more_c != 0)
		len++;
	if (w > len)
	{
		for (a = 1; a < w - len + 1; a++)
			buffer[a] =bdd;
		buffer[a] ='\0';
		if (f & 1 && bdd == ' ')
			buffer[--index] = '0', len++;
		if (more_c != 0)
			len++;
		if (w > len)
		{
			for (a = 1; a < w - len + 1; a++)
				buffer[a] = bdd;
			buffer[a] = '\0';
			if (f & 1 && bdd == ' ')
			{
				if (more_c)
					buffer[--index] = more_c;
				return (write(1, &buffer[index], len) + write(1, &buffer[1], a - 1));
			}
			else if (!(f & 1) && bdd == ' ') 
			{
				if (more_c)
					buffer[--index] = more_c;
				return (write(1, &buffer[1], a - 1) + write(1, &buffer[index], len));
			}
			else if (!(f & 1) && bdd == ' ')
			{
				if (more_c)
					buffer[--index] = more_c;
				return (write(1, &buffer[1], a-1) + write(1, &buffer[index], len));
			}
			if (more_c)
				buffer[--bdd_st] = more_c;
			return (write(1, &buffer[bdd_st], a - bdd_st) + write(1, &buffer[index], len - (1 - bdd_st)));
		}
	}
	if (more_c)
		buffer[--index] = more_c;

	return (write(1, &buffer[index], len));
}
