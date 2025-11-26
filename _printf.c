#include "main.h"

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints a character
 * @list: va_list containing the character argument
 *
 * Return: 1 (number of characters printed)
 */
int print_char(va_list list)
{
	char c = va_arg(list, int); /* char est promu à int */

	return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @list: va_list containing the string argument
 *
 * Return: Number of characters printed
 */
int print_string(va_list list)
{
	char *s = va_arg(list, char *);
	int count = 0;

	/* Gérer le cas où la chaîne est NULL */
	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		_putchar(*s++);
		count++;
	}

	return (count);
}

/**
 * print_percent - Prints a percent sign
 * @list: va_list (unused)
 *
 * Return: 1 (number of characters printed)
 */
int print_percent(__attribute__((unused))va_list list)
{
	return (_putchar('%'));
}

/* --- Fonctions pour Exercice 2 (d, i) --- */

/**
 * print_number - Helper function to print a positive number recursively
 * @n: The number to print
 *
 * Return: Number of characters printed
 */
int print_number(long int n)
{
    int count = 0;
    
    if (n < 0)
    {
        /* Ne devrait pas arriver ici si bien géré dans print_integer */
        n = -n;
    }

    if (n / 10)
    {
        count += print_number(n / 10);
    }
    
    _putchar((n % 10) + '0');
    count++;

    return (count);
}

/**
 * print_integer - Handles the %d and %i specifiers
 * @list: The va_list containing the integer argument
 *
 * Return: Number of characters printed
 */
int print_integer(va_list list)
{
    int n = va_arg(list, int);
    int printed_chars = 0;
    
    /* Gérer le signe */
    if (n < 0)
    {
        printed_chars += _putchar('-');
        
        /* Gérer INT_MIN sans débordement en castant en unsigned */
        if (n == -2147483648) /* INT_MIN */
        {
            /* Affichage du signe géré, on passe la valeur absolue en unsigned long */
            printed_chars += print_number(2147483648UL);
        }
        else
        {
            printed_chars += print_number(-n);
        }
    }
    else
    {
        printed_chars += print_number(n);
    }

    return (printed_chars);
}
