#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* Pour va_list */
#include <unistd.h> /* Pour _putchar/write */
#include <limits.h> /* IMPORTANT: Pour INT_MIN */
#include <stdlib.h> /* Utile pour la gestion des chaînes/nombres */

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

/* ------------------------------------------------------------------ */
/* Functions pour les Spécificateurs */
/* ------------------------------------------------------------------ */

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

/* Nouveau: Gère %d et %i. C'est elle qui appelle print_number pour l'affichage. */
int print_integer(va_list args); 

/* ------------------------------------------------------------------ */
/* Fonctions Utilitaires (Helpers) */
/* ------------------------------------------------------------------ */

int _putchar(char c);

/* Mise à jour: Change le type d'argument à long int pour gérer INT_MIN sans débordement. */
int print_number(long int n); 

#endif
