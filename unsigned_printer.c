#include "main.h"

/**
 * unsigned_printer - unsigned num
 * @is_neg: Number indicating if
 * the num is negative
 * @index: Index
 * @buffer: array of chars
 * Return: n( chars).
 */

int unsigned_printer(int is_neg, int index, char buffer[])
{
	int len = BUFF_SIZE - index - 1;

	(void)is_neg;
	return (write(1, &buffer[index], len));
}
