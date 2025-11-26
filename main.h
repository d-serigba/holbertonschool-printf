#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h> /* Ajouté pour INT_MIN */
#include <stdlib.h>

/**
 * struct convert - Struct for conversion specifiers
 * @sym: The format specifier (e.g., "c", "s", "%", "d", "i")
 * @f: The function associated (pointeur de fonction)
 */
typedef struct convert
{
    char *sym;
    int (*f)(va_list);
} conver_t;

/* ------------------------------------------------------------------ */
/* Fonction Principale */
/* ------------------------------------------------------------------ */

/**
 * _printf - Produit une sortie formatée vers stdout.
 * @format: Chaîne de caractères contenant zéro ou plusieurs directives.
 * Gère les spécificateurs de conversion suivants :
 * - 'c': caractère simple
 * - 's': chaîne de caractères
 * - '%': caractère pourcentage
 * - 'd' / 'i': entier signé (decimal et integer)
 *
 * NOTE: Cette implémentation ne gère pas:
 * - Les caractères de drapeau (flags)
 * - La largeur de champ (field width)
 * - La précision (precision)
 * - Les modificateurs de longueur (length modifiers)
 *
 * Return: Le nombre de caractères imprimés (excluant le null byte de fin de chaîne).
 */
int _printf(const char *format, ...);

/* ------------------------------------------------------------------ */
/* Fonctions de Parsing et de Décomposition */
/* ------------------------------------------------------------------ */

/* * parser - Fonction responsable de parcourir le format, 
 * de chercher le spécificateur et d'appeler la bonne fonction.
 */
int parser(const char *format, conver_t f_list[], va_list arg_list);

/* ------------------------------------------------------------------ */
/* Fonctions d'Impression des Spécificateurs */
/* ------------------------------------------------------------------ */

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);

/* ------------------------------------------------------------------ */
/* Fonctions Utilitaires (Helpers) */
/* ------------------------------------------------------------------ */

int _putchar(char c);

/* Affiche un nombre (utilisée par print_integer, prend long int pour INT_MIN) */
int print_number(long int n); 

#endif /* MAIN_H */
