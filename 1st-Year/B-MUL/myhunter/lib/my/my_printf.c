/*
** EPITECH PROJECT, 2020
** my_printf.c
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

char *get_flag(char *str, int *i, va_list list)
{
    va_list copy;

    va_copy(copy, list);
    for (int j = 0; j < 5; j++) {
        if (str[*i] == FLAG_FUNCS[j].flag) {
            FLAG_FUNCS[j].type_flag(str, *i, copy);
            str += 1;
        }
    }
    va_end(copy);
    return (str);
}

char *get_preci(char *str, char **preci, int *i, char **wdt)
{
    for (int j = 0; j < 2; j++) {
        if (str[*i] == PRECISION_FUNCS[j].precision) {
            *preci = PRECISION_FUNCS[j].type_preci(str, *i);
            if (*preci[0] == 'Z') {
                str += my_strlen(my_getstr(gtnb_pt(str + *i))) + *i;
            } else
                str += my_strlen(my_getstr(gtnb_pt(str + *i))) + *i + 1;
            *i = 0;
        }
    }
    return (str);
}

char *get_width(char *str, int *i, char **wdt, va_list list)
{
    va_list copy;

    va_copy(copy, list);
    for (int j = 0; j < 10; j++) {
        if (str[*i] == WIDTH_FUNCS[j].width) {
            *wdt = WIDTH_FUNCS[j].type_width(str, *i, copy);
            str += my_strlen(*wdt);
        }
    }
    return (str);
}

char *get_specifer(char *str, char *preci, va_list list, int i)
{
    for (int j = 0; j < 16; j++) {
        if (str[i] == SPECIFER_FUNCS[j].specif) {
            SPECIFER_FUNCS[j].type_print(list, preci);
            preci[0] = 'A';
        }
    }
    return (preci);
}

int my_printf(char *str, ...)
{
    char *preci = malloc(sizeof(char) * my_strlen(str) + 1);
    char *wdt = malloc(sizeof(char) * my_strlen(str) + 1);
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '%') {
            my_putchar(str[i]);
        } else {
            i++;
            str = get_flag(str, &i, list);
            str = get_width(str, &i, &wdt, list);
            str = get_preci(str, &preci, &i, &wdt);
            preci = get_specifer(str, preci, list, i);
        }
    }
    va_end(list);
    return (0);
}
