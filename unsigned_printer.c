#include "main.h"

/**
 * unsigned_printer - unsigned num
 * @is_neg: Number indicating if
 * the num is negative
 * @index: Index
 * @buffer: array of chars
 * Return: n( chars).
 */

int unsigned_printer(int is_neg, int index, char buffer[], int f, int w, int p)
{
	int len = BUFF_SIZE - index - 1;
	int a = 0;
	char bdd;
	
	bdd = ' ';

	(void)is_neg;

	if (p == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);

	while (p > 0 && p < len)
		bdd = ' ';

	while (p > len)
	{
		buffer[--index] = '0';
		len++;
	}

	if ((f & 4) && !(f & 1))
		bdd = '0';

	if (w > len)
	{
		for (a = 0; a < w - len; a++)
			buffer[a] = bdd;

		buffer[a] = '\0';

		if (f & 1)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[index], len));
		}
	}

	return (write(1, &buffer[index], len));
}
