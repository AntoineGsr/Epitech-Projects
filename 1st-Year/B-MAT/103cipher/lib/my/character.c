/*
** EPITECH PROJECT, 2020
** character.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int character(va_list list, char *preci)
{
    my_putchar(va_arg(list, int));
    return (0);
}
