#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>  // Required for va_list, va_start, va_arg, va_end macros
#include <unistd.h>  // Required for write() system call

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing conversion specifiers
 * 
 * This is the main function that mimics the behavior of printf.
 * It processes the format string and calls appropriate handlers
 * for each conversion specifier (%c, %s, %d, %i, etc.)
 * 
 * Return: Number of characters printed
 */
int _printf(const char *format, ...);

/**
 * _putchar - Writes a single character to stdout
 * @c: Character to be written
 * 
 * This function uses the write() system call to output
 * a single character to standard output (file descriptor 1)
 * 
 * Return: 1 on success, -1 on error
 */
int _putchar(char c);

/**
 * print_char - Handles the %c conversion specifier
 * @args: va_list containing the character argument
 * 
 * Extracts a character from the variable argument list
 * and prints it using _putchar
 * 
 * Return: Number of characters printed (always 1)
 */
int print_char(va_list args);

/**
 * print_string - Handles the %s conversion specifier
 * @args: va_list containing the string argument
 * 
 * Extracts a string from the variable argument list
 * and prints each character. Handles NULL strings by
 * printing "(null)"
 * 
 * Return: Number of characters printed
 */
int print_string(va_list args);

/**
 * print_percent - Handles the %% conversion specifier
 * @args: va_list (unused for this function)
 * 
 * Prints a literal '%' character when %% is encountered
 * in the format string
 * 
 * Return: Number of characters printed (always 1)
 */
int print_percent(va_list args);

/**
 * print_number - Handles %d and %i conversion specifiers
 * @args: va_list containing the integer argument
 * 
 * Extracts an integer from the variable argument list,
 * handles negative numbers by printing '-' sign,
 * and calls print_number_recursive to print the digits
 * 
 * Return: Number of characters printed
 */
int print_number(va_list args);

/**
 * print_number_recursive - Helper function to print integer digits
 * @n: Unsigned integer to print
 * 
 * Recursively divides the number by 10 to extract and print
 * each digit from left to right. Base case is when n < 10
 * 
 * Return: Number of characters printed
 */
int print_number_recursive(unsigned int n);

#endif /* MAIN_H */
