#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* Nécessaire pour va_list */
#include <unistd.h> /* Nécessaire pour _putchar/write */
#include <limits.h> /* Nécessaire pour gérer INT_MIN proprement */
#include <stdlib.h> /* Utile pour la gestion des nombres */

/**
 * struct convert - Struct pour les spécificateurs de conversion
 * @sym: Le spécificateur de conversion (ex: "c", "s", "%", "d", "i")
 * @f: Le pointeur vers la fonction de gestion associée
 */
typedef struct convert
{
    char *sym;
    int (*f)(va_list);
} conver_t;

/* ------------------------------------------------------------------ */
/* Fonction Principale (_printf) */
/* ------------------------------------------------------------------ */

/**
 * _printf - Produit une sortie formatée vers stdout.
 * @format: Chaîne de caractères. Le format est composé de zéro ou plusieurs directives.
 *
 * Gère les spécificateurs de conversion requis par les Exercices 1 et 2:
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
 * - La gestion interne du buffer de la fonction printf de la librairie C.
 * L'output est écrit directement sur stdout (via _putchar).
 *
 * Return: Le nombre de caractères imprimés (excluant le null byte de fin de chaîne).
 */
int _printf(const char *format, ...);

/* ------------------------------------------------------------------ */
/* Fonctions de Parsing et de Décomposition */
/* ------------------------------------------------------------------ */

/* * parser - Fonction responsable de parcourir la chaîne de format, 
 * de chercher le spécificateur et d'appeler la fonction associée.
 */
int parser(const char *format, conver_t f_list[], va_list arg_list);

/* ------------------------------------------------------------------ */
/* Fonctions d'Impression des Spécificateurs */
/* ------------------------------------------------------------------ */

int print_char(va_list args);       /* Gère 'c' */
int print_string(va_list args);     /* Gère 's' */
int print_percent(va_list args);    /* Gère '%' */
int print_integer(va_list args);    /* Gère 'd' et 'i' */

/* ------------------------------------------------------------------ */
/* Fonctions Utilitaires (Helpers) */
/* ------------------------------------------------------------------ */

int _putchar(char c);

/* Affiche un nombre (utilisée par print_integer, prend long int ou unsigned int) */
int print_number(long int n); 

#endif /* MAIN_H */
