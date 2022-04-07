/*
** EPITECH PROJECT, 2020
** diez.c
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

char *diez(char *str, int i, va_list copy)
{
    char flag = str[i + 1];

    for (i; str[i] != 'x' && str[i] != 'X' && str[i] != 'o' && str[i] != '\0';
        i++);
    if (str[i] == 'o')
        my_putchar('0');
    if (str[i] == 'x')
        my_putstr("0x");
    if (str[i] == 'X')
        my_putstr("0X");
    return NULL;
}
