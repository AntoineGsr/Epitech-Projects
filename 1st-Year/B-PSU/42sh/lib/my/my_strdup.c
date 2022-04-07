/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** mystrdup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    int j = 0;
    char *dest;

    while (src[i] != '\0') {
        i++;
    }
    dest = malloc(sizeof(char) * (i + 1));
    for (; src[j] != '\0'; j++) {
        dest[j] = src[j];
    }
    dest[j] = '\0';
    return (dest);
}
