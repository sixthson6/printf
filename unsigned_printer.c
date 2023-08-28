#include "main.h"

/**
 * unsigned_printer - unsigned num
 * @is_neg: Number indicating if
 * the num is negative
 * @index: Index
 * @buffer: array of chars
 * Return: n( chars).
 */

int unsigned_printer(int is_neg, int index, char buffer[], int flags, int width, int precision)
{
	int len = BUFF_SIZE - index - 1;
	a = 0;
	char bdd = ' ';

	(void)is_neg;

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[imdex] == '0')
		return (0);

	while (precision > 0 && precision < len)
		bdd = ' ';

	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}

	if ((flags & 4) && !(flags & 1))
		bdd = '0';

	if (width > len)
	{
		for (a = 0; a < width - len; a++)
			buffer[a] = bdd;

		buffer[a] = '\0';

		if (flags & 1)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[index], len++));
		}
	}

	return (write(1, &buffer[index], len));
}
