/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** lib
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    if (my_strlen(str) < my_strlen(to_find))
        return NULL;
    for (; str[i] != '\0'; i++) {
        if (str[i] == to_find[j]) {
            j += 1;
        } else
            j = 0;
        if (to_find[j] == '\0')
            return (str);
    }
    return NULL;
}
