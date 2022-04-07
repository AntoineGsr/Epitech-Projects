/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** str copy pour n car
*/

#include <stdio.h>
#include "my.h"
#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i <= n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    } dest[i] = '\0';
    return (dest);
}