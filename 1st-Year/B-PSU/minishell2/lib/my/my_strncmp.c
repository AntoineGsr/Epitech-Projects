/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** lib
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int value = 0;

    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    while (i < n && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    if (i < n)
        return (1);
    return (0);
}
