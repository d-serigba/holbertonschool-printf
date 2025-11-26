#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: Character to print
 *
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - Prints an integer using recursion
 * @n: The integer
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n / 10)
		count += print_number(n / 10);

	count += _putchar(n % 10 + '0');

	return (count);
}
