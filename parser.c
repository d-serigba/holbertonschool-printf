#include "main.h"

/**
 * parser - Goes through the format string and calls functions
 * @format: The format string
 * @f_list: Array of conversion specifiers and functions
 * @arg_list: The arguments passed to _printf
 *
 * Return: Number of printed characters
 */
int parser(const char *format, conver_t f_list[], va_list arg_list)
{
	int i = 0, j, printed = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == *(f_list[j].sym))
				{
					printed += f_list[j].f(arg_list);
					i += 2;
					break;
				}
			}

			if (f_list[j].sym == NULL)
			{
				_putchar(format[i]);
				printed++;
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			printed++;
			i++;
		}
	}

	return (printed);
}
