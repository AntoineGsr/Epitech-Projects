/*
** EPITECH PROJECT, 2020
** string.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int string(va_list list, char *preci)
{
    int i = my_getnbr(preci);
    char *str = va_arg(list, char *);
    int s_str = my_strlen(str);

    if (i < s_str && (preci[0] >= '0' || preci[0] == 'Z') && preci[0] != 'A') {
        for (int j = 0; j < i; j++)
            my_putchar(str[j]);
        return (0);
    }
    my_putstr(str);
    return (0);
}
