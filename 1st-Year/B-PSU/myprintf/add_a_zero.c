/*
** EPITECH PROJECT, 2020
** add_a_zero.c
** File description:
** 
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "specifer.h"
#include "precision.h"
#include "flag.h"
#include "width.h"

int get_preci_zero(char *str, int i, int size)
{
    int pc = my_getnbr(str + i + my_strlen(my_getstr(size)) + 2);
    return (pc);
}

int print_space_or_zero(int width, int preci, int i, int size)
{
    for (width; width > 0; width--) {
        if (size < preci || preci == 0) {
            my_putchar('0');
        } else
            my_putchar(' ');
    }
    return (0);
}

char *add_a_zero(char *str, int i, va_list copy)
{
    int width = 0;
    int nb_copy = va_arg(copy, int);
    int size_nb_copy = my_strlen(my_getstr(nb_copy));
    int preci = 0;

    if (str[i - 1] == '%' && str[i + 1] >= '0' && str[i + 1] <= '9') {
        preci = get_preci_zero(str, i, my_getnbr(str + i + 1));
        width = my_getnbr(str + i + 1);
        if (preci > width) {
            width = width - size_nb_copy - preci;
        } else if (preci > size_nb_copy) {
            width = width - preci;
        } else
            width = width - size_nb_copy;
        print_space_or_zero(width, preci, i, my_getnbr(str + i + 1));
    }
    return NULL;
}
