/*
** EPITECH PROJECT, 2020
** no_printable.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include "specifer.h"

char *octal_no_printable(char str)
{
    unsigned int nb_octal = 0;
    unsigned int nb_decimal = str;
    unsigned int power = 1;
    char result[3];
    int i = 2;
    int size_max = 0;

    for (size_max; size_max < 3; size_max++) {
        result[size_max] = '0';
    }
    result[size_max] = '\0';
    if (nb_decimal < 0)
        nb_decimal = -nb_decimal;
    for (i; nb_decimal != 0; i--) {
        nb_octal = (nb_decimal % 8);
        nb_decimal = nb_decimal / 8;
        result[i] = '0' + nb_octal;
    }
    my_printf("%c%s", 92, result);
    return NULL;
}

int no_printable(va_list list, char *preci)
{
    char *str = va_arg(list, char *);
    int ascii_value = 0;
    for (int i = 0; i < my_strlen(str); i++) {
        ascii_value = str[i];
        if (ascii_value >= 32 && ascii_value < 127) {
            my_putchar(str[i]);
        } else
            octal_no_printable(str[i]);
    }
    return (0);
}
