/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** lib
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int destsize = my_strlen(dest);
    int i = 0;

    for (i; src[i] != '\0' && i < nb; i++) {
        dest[destsize + i] = src[i];
    }
    dest[destsize + i] = '\0';
    return (dest);
}
