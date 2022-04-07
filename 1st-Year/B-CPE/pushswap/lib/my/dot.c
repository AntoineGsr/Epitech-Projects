/*
** EPITECH PROJECT, 2020
** dot.c
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

char *dot(char *str, int i)
{
    int pre_to_char = gtnb_pt(str + i + 1);
    char *preci = malloc(sizeof(char) * my_strlen(str + i + 1) + 1);

    str += i + 1;
    if (str[0] < '0' || str[0] > '9') {
        preci[0] = 'Z';
        return (preci);
    }
    preci = my_getstr(pre_to_char);
    return (preci);
}
