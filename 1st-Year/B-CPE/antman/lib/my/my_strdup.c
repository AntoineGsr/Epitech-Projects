/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** lib
*/

#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (; src[i] != '\0'; i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return (str);
}
