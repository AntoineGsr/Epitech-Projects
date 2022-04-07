/*
** EPITECH PROJECT, 2020
** unsigned_long.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int my_put_nbr_long(unsigned long nb)
{
    unsigned long nb2 = nb;

    if (nb2 >= 10)
        my_put_nbr_long(nb2 / 10);
    my_putchar((nb2 % 10) + 48);
    return (0);
}

int unsigned_long(va_list list, char *preci)
{
    int i = my_getnbr(preci);
    int j = 0;
    unsigned long nb = va_arg(list, unsigned long);
    char *display = malloc(sizeof(char) * i + 1);
    char *nb_arr = my_getstr_long(nb);

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
    my_put_nbr_long(nb);
    return (0);
}
