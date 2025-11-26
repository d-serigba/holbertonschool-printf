#include "main.h"

/**
 * print_integer - Prints an integer
 * @args: Argument list
 *
 * Return: Number of printed digits
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);

	return (print_number(n));
}
