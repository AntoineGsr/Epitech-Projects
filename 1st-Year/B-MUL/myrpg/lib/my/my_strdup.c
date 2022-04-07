/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** str copy
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *dup = malloc(len + 50);

    if (dup == NULL)
        return (NULL);
    dup = my_strcpy(dup, str);
    dup[len] = '\0';
    return (dup);
}