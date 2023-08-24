#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE 1024
#define S_LONG 2
#define S_SHORT 1

/**
 * struct sym - struct for _printf
 * @sym: string holder
 * @_print: func pointer to ***_fun functions
 */

typedef struct sym
{
	char sym;
	int (*_print)(va_list, char[]);
} format_types;

int _printf(const char *format, ...);
int specifier_print_function(const char *format, int *index,
		va_list arg, char buffer[]);
void buffer_printer(char buffer[], int *buffer_index);

/* helper funtions that print*/
int write_function(char c, char buffer[]);
int write_number_function(int is_neg, int index, char buffer[]);
int write_num(int index, char buffer[], int len);
long int size_number_function(long int num, int size);

int handle_format_argument(const char **format, va_list arguments);

int int_function(va_list arg, char buffer[]);
int char_function(va_list arg, char buffer[]);
int string_function(va_list arg, char buffer[]);
int percent_function(va_list arg, char buffer[]);
int binary_function(va_list arg, char buffer[]);

int unsigned_function(va_list arg, char buffer[]);
int octal_function(va_list arg, char buffer[]);
int hexadecimal_function(va_list arg, char buffer[]);
int hexa_print(va_list types, char map[], char buffer[]);

int unsigned_printer(int is_neg, int index, char buffer[]);

int hexa_convert(char ascii_c, char buffer[], int i);
int print_printable_func(char n);
int nonprintable_function(va_list arg, char buffer[]);

int pointer_helper_function(char buffer[], int index, int len);
#endif
