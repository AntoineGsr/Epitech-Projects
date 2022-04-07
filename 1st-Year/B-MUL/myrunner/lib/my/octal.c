/*
** EPITECH PROJECT, 2020
** octal.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int octal_preci(char *preci, long long int nb_octal)
{
    int i = my_getnbr(preci);
    int j = 0;
    int s_octal = my_strlen(my_getstr(nb_octal)) - 1;
    char *display = malloc(sizeof(char) * i + 1);
    char *arr_octal = malloc(sizeof(char) * s_octal + 1);

    if ((preci[0] == 'Z' || preci[0] == '0') && nb_octal == 0)
        return (0);
    arr_octal = my_getstr(nb_octal);
    for (j ; j < i; j++)
        display[j] = '0';
    display[j] = '\0';
    j--;
    if (i > my_strlen(my_getstr_long(nb_octal))) {
        for (j, s_octal; s_octal >= 0; j--, s_octal--)
            display[j] = arr_octal[s_octal];
        my_putstr(display);
        return (0);
    }
    return (1);
}

char *neg_nb_decimal(char *preci, long long int nb_octal, int nb_decimal)
{
    int preci_int = 0;
    int stock = nb_decimal * (-1);
    unsigned int power = 1;

    while (nb_decimal != 0) {
        nb_octal = nb_octal + (nb_decimal % 8) * power;
        nb_decimal = nb_decimal / 8;
        power = power *  10;
    }
    nb_octal = 37777777778 - nb_octal;
    preci_int = octal_preci(preci, nb_octal);
    if (preci_int == 0)
        return (0);
    my_putstr(my_getstr_long(nb_octal));
    return NULL;
}

int octal(va_list list, char *preci)
{
    long long int nb_octal = 0;
    int nb_decimal = va_arg(list, int);
    unsigned int power = 1;
    int preci_int = 0;

    if (nb_decimal < 0) {
        nb_decimal = -nb_decimal;
        neg_nb_decimal(preci, nb_octal, nb_decimal);
        return (0);
    }
    while (nb_decimal != 0) {
        nb_octal = nb_octal + (nb_decimal % 8) * power;
        nb_decimal = nb_decimal / 8;
        power = power *  10;
    }
    preci_int = octal_preci(preci, nb_octal);
    if (preci_int == 0)
        return (0);
    my_put_nbr(nb_octal);
    return (0);
}
