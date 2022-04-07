/*
** EPITECH PROJECT, 2020
** pos_or_neg.c
** File description:
** lib
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

char *pos_or_neg(char *str, int i, va_list copy)
{
    int nb = va_arg(copy, int);

    if (nb >= 0)
        my_putchar('+');
    return NULL;
}
