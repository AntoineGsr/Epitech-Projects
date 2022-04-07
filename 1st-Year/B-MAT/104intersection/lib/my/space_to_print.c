/*
** EPITECH PROJECT, 2020
** space_to_print.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include "specifer.h"
#include "precision.h"
#include "flag.h"

int get_preci_space(char *str, int i, int size)
{
    int pc = my_getnbr(str + i + my_strlen(my_getstr(size)) + 2);
    return (pc);
}

char *space_to_print(char *str, int i, va_list copy)
{
    int width = 0;
    int nb_copy = va_arg(copy, int);
    int size_nb_copy = my_strlen(my_getstr(nb_copy));
    int preci = 0;

    if (str[i - 1] == '%' && str[i + 1] >= '0' && str[i + 1] <= '9') {
        preci = get_preci_space(str, i, my_getnbr(str + i + 1));
        width = my_getnbr(str + i + 1);
        if (preci > width) {
            width = width - size_nb_copy - preci;
        } else if (preci > size_nb_copy) {
            width = width - preci;
        } else
            width = width - size_nb_copy;
        my_putchar(' ');
        for (width--; width > 0; width--)
            my_putchar(' ');
    }
    return NULL;
}
