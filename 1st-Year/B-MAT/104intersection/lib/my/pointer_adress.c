/*
** EPITECH PROJECT, 2020
** test.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"

char *array_hexap(unsigned long nb_decimal, char *nb_hexa, int i,
unsigned long reminder)
{
    if (nb_decimal < 0)
        nb_decimal = -nb_decimal;
    while (nb_decimal != 0) {
        reminder = nb_decimal % 16;
        nb_decimal = nb_decimal / 16;
        if (reminder >= 10) {
            nb_hexa[i] = 'a' + (reminder % 10);
        } else
            nb_hexa[i] = reminder + '0';
        i++;
    }
    nb_hexa[i] = '\0';
    return (nb_hexa);
}

unsigned long *hexa_pointer(unsigned long nb_decimal)
{
    char *nb_hexa = NULL;
    int i = 0;
    unsigned long reminder = 0;
    unsigned long formalloc = nb_decimal;
    int count = 0;

    if (nb_decimal == 0) {
        my_putchar('0');
        return NULL;
    }
    while (formalloc != 0) {
        formalloc = formalloc / 10;
        count++;
    }
    nb_hexa = malloc(sizeof(char) * count);
    nb_hexa = array_hexap(nb_decimal, nb_hexa, i, reminder);
    my_putstr(my_revstr(nb_hexa));
    return NULL;
}

int pointer_adress(va_list list, char *preci)
{
    void *point = va_arg(list, void *);
    unsigned long adress_value = (unsigned long) point;
    int count = 0;
    unsigned long formalloc = adress_value;

    while (formalloc != 0) {
        formalloc = formalloc / 10;
        count++;
    }
    if (adress_value == 0) {
        my_putstr("(nil)");
        return (0);
    }
    my_putstr("0x");
    hexa_pointer(adress_value);
    return (0);
}
