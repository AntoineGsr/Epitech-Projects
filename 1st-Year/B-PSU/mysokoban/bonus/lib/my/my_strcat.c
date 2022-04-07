/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** lib
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int destsize = 0;
    int i = 0;

    destsize = my_strlen(dest);
    for (i; src[i] != '\0'; i++) {
        dest[destsize + i] = src[i];
    }
    dest[destsize + i] = '\0';
    return (dest);
}
