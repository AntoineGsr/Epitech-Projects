/*
** EPITECH PROJECT, 2020
** width_nb.c
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
#include "width.h"

int get_preci_width(char *str, int i, int size)
{
    int pc = my_getnbr(str + i + my_strlen(my_getstr(size)) + 1);
    return (pc);
}

char *width_nb(char *str, int i, va_list copy)
{
    int wid_to_char = gtnb_pt(str + i);
    char *wdt = my_getstr(wid_to_char);
    int width = 0;
    int nb_copy = va_arg(copy, int);
    int size_nb_copy = my_strlen(my_getstr(nb_copy));
    int preci = get_preci_width(str, i, my_getnbr(str + i));

    if (str[i - 1] == '%') {
        width = my_getnbr(str + i);
        if (preci > width) {
            return (wdt);
        } else if (preci > size_nb_copy) {
            width = width - preci;
        } else
            width = width - size_nb_copy;
        my_putchar(' ');
        for (width--; width > 0; width--)
            my_putchar(' ');
    }
    return (wdt);
}
