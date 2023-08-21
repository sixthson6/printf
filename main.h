#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/**
 * struct printer - struct for _printf
 * @sum: string holder
 * @_print: func pointer to ***_fun functions
 */

typedef struct printer
{
	char *sym;
	void (*_print)(va_list arg);
} print_funct;

void printNumber(int num);
void char_fun(va_list arg);
void int_fun(va_list arg);
void str_fun(va_list arg);
void pr_fun(va_list arg);
int print_str(char *str);
void printNumber(int number);
int _printf(const char *format, ...);

#endif
