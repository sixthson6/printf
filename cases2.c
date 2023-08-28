#include "main.h"
/**
 * pointer_function - Prints pointer variable
 * @arg: arguments
 * @buffer: Buffer array
 * @f:  Calculates flags
 * @w: get width
 * @p: get recision
 * Return: no. of bytes
 */

int pointer_function(va_list arg, char buffer[], int f, int w, int p)
{
	char sep = ' ', c = 0;
	int index = BUFF_SIZE - 2, len = 2, sep_st = 1;
	size_t number_add;
	char map[] = "0123456789abcdef";
	void *address = va_arg(arg, void *);


	(void)w;
	(void)s;
	(void)p;

	if (address == NULL)
	{
		return ((write(1, "(nil)", 5)));
	}
	buffer[BUFF_SIZE] = '\0';

	number_add = (unsigned long)address;

	while (number_add > 0)
	{
		buffer[index] = map[number_add % 16];
		number_add /= 16;
		len++;
	}
	if ((f & 4) && !(f & 1))
	{
		sep = '0';
	}
	if (f & 2)
	{
		c = '+', len++;
	}
	else if (f & 16)
	{
		c = ' ', len++;
	}
	index++;

	return (pointer_printer(buffer, index, len, w, f, sep, c, sep_st));
}

/**
 * reverse_function - Prints reverse string.
 * @arg: arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates flags
 * @w: get width
 * @p: get_precision
 * Return: Numbers of bytes
 */
int reverse_function(va_list arg, char buffer[], int f, int w, int p)
{
	int count = 0, i, j;
	char *str;

	void(w);
	void(f);
	void(buffer);

	str = va_arg(arg, char *);

	if (str == NULL)
	{
		void(precision);
		str = "Null";
	}

	for (i = 0; str[i]; i++)
	{
		for (i = i - 1; i >= 0; i--)
		{
			j = str[i];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * rot13string_function - Print a string in rot13.
 * @arg: arguments
 * @buffer: Buffer array
 * @f: active flags
 * @w: get_width
 * @p: get_precision specification
 * Return: Numbers of bytes printed
 */

int rot13string_function(va_arg arg, char buffer[], int f, int w, int p)
{
	size_t i, j;
	int count = 0;
	char *str;
	char c;
	char input_arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output_arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(arg, char *);

	void(p);
	void(w);
	void(buffer);
	void(f);

	if (str == NULL)
		str = "Nil";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; input_arr[j]; j++)
		{
			if (inut_arr[j] == str[i])
			{
				c = output[j];
				write(1, &c, 1);
				count++;
				break;
			}
		}


		if (!input_arr[j])
		{
			c = str[i];
			write(1, &c, 1);
			count++;
		}

	}
	return (count);
}
