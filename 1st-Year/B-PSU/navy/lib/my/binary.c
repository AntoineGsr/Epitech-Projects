/*
** EPITECH PROJECT, 2020
** binary.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *array_bin(unsigned int nb_decimal, char *nb_bin,
unsigned int i)
{
    unsigned int reminder = 0;

    if (nb_decimal < 0)
        nb_decimal = -nb_decimal;
    while (nb_decimal != 0) {
        reminder = nb_decimal % 2;
        nb_decimal = nb_decimal / 2;
        nb_bin[i] = reminder + '0';
        i++;
    }
    nb_bin[i] = '\0';
    return (nb_bin);
}

int binary(va_list list, char *preci)
{
    unsigned int nb_decimal = va_arg(list, unsigned int);
    char *nb_bin = NULL;
    unsigned int i = 0;
    unsigned int formalloc = nb_decimal;
    unsigned int count = 0;

    if (nb_decimal == 0) {
        my_putchar('0');
        return (0);
    }
    while (formalloc != 0) {
        formalloc = formalloc / 10;
        count++;
    }
    nb_bin = malloc(sizeof(char) * count + 1);
    nb_bin = array_bin(nb_decimal, nb_bin, i);
    my_putstr(my_revstr(nb_bin));
    return (0);
}
