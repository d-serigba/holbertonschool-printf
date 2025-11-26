#include "main.h"

/**
 * print_char - Prints a character
 * @args: Argument list
 *
 * Return: 1
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}
