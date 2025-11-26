#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct convert - Struct for conversion specifiers
 * @sym: The format specifier
 * @f: The function associated
 */
typedef struct convert
{
	char *sym;
	int (*f)(va_list);
} conver_t;

/* Main printf function */
int _printf(const char *format, ...);

/* Parser */
int parser(const char *format, conver_t f_list[], va_list arg_list);

/* Printing functions */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);

/* Utils */
int print_number(int n);
int _putchar(char c);

#endif
