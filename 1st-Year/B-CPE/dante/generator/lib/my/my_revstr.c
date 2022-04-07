/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** lib
*/

#include "my.h"

char *my_revstr(char *str)
{
    int length = my_strlen(str) - 1;
    char stock;

    for (int i = 0; i < length; i++, length--) {
        stock = str[i];
        str[i] = str[length];
        str[length] = stock;
    }
    return (str);
}
