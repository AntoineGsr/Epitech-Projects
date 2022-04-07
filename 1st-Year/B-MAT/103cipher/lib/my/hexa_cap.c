/*
** EPITECH PROJECT, 2020
** hexa_cap.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int hexa_cap_preci(char *nb_hexa, char *preci)
{
    int i = my_getnbr(preci);
    int s_hexa = my_strlen(nb_hexa) - 1;
    int j = 0;
    char *display = malloc(sizeof(char) * i + 1);

    nb_hexa = my_revstr(nb_hexa);
    for (j ; j < i; j++)
        display[j] = '0';
    display[j] = '\0';
    j--;
    if (i > my_strlen(nb_hexa)) {
        for (j, s_hexa; s_hexa >= 0; j--, s_hexa--)
            display[j] = nb_hexa[s_hexa];
        my_putstr(display);
        return (0);
    }
    my_putstr(nb_hexa);
    return (0);
}

char *array_hexa_cap(unsigned int nb_decimal, char *nb_hexa,
unsigned int i, char *preci)
{
    unsigned int reminder = 0;

    if (nb_decimal < 0)
        nb_decimal = -nb_decimal;
    while (nb_decimal != 0) {
        reminder = nb_decimal % 16;
        nb_decimal = nb_decimal / 16;
        if (reminder >= 10) {
            nb_hexa[i] = 'A' + (reminder % 10);
        } else
            nb_hexa[i] = reminder + '0';
        i++;
    }
    nb_hexa[i] = '\0';
    hexa_cap_preci(nb_hexa, preci);
    return (nb_hexa);
}

int hexa_cap(va_list list, char *preci)
{
    unsigned int nb_decimal = va_arg(list, unsigned int);
    char *nb_hexa = NULL;
    int i = 0;
    unsigned int reminder = 0;
    unsigned int formalloc = nb_decimal;
    unsigned int count = 0;

    if ((preci[0] == 'Z' || preci[0] == '0') && nb_decimal == 0)
        return (0);
    while (formalloc != 0) {
        formalloc = formalloc / 10;
        count++;
    }
    nb_hexa = malloc(sizeof(char) * count + 1);
    if (nb_decimal == 0 && preci[0] == '\0') {
        my_putchar('0');
        return (0);
    }
    array_hexa_cap(nb_decimal, nb_hexa, i, preci);
    return (0);
}
