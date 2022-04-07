/*
** EPITECH PROJECT, 2020
** integer.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int integer(va_list list, char *preci)
{
    int i = my_getnbr(preci);
    int j = 0;
    int nb = va_arg(list, int);
    char *display = malloc(sizeof(char) * i + 1);
    char *nb_arr = my_getstr(nb);

    if ((preci[0] == 'Z' || preci[0] == '0') && nb == 0)
        return (0);
    if (i > my_strlen(nb_arr)) {
        for (j ; j < i; j++)
            display[j] = '0';
        display[j] = '\0';
        j = my_strlen(nb_arr) - 1;
        for (j, i = i - 1; j >= 0; j--, i--)
            display[i] = nb_arr[j];
        my_putstr(display);
        return (0);
    }
    my_put_nbr(nb);
    return (0);
}
