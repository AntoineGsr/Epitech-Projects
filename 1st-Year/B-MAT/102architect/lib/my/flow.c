/*
** EPITECH PROJECT, 2020
** flow.c
** File description:
** lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int error(char *nb)
{
    int count_dot = 0;

    for (int j = 0; nb[j] != '\0'; j++) {
        if (nb[j] == '.')
            count_dot++;
    }
    if (count_dot != 1)
        return (1);
    return (0);
}

int size_unity(int formalloc, int count)
{
    while (formalloc != 0) {
        formalloc = formalloc / 10;
        count++;
    }
}

char *array_decimal(char *nb2, float decimal_flow, int delete)
{
    int j = 0;

    for (j; j < 6; j++) {
        decimal_flow = decimal_flow * 10;
        delete = decimal_flow;
        nb2[j] = delete + '0';
        decimal_flow = decimal_flow - delete;
    }
    nb2[j] = '\0';
    return (nb2);
}

int flow(va_list list, char *preci)
{
    float value_flow = va_arg(list, double);
    int count = size_unity((int) value_flow, count);
    char *nb = malloc(sizeof(char) * count + 1);
    char *nb2 = malloc(sizeof(char) * 8);
    int unity = (int) value_flow;
    float decimal_flow = value_flow - (int) value_flow;
    char decimal = decimal_flow * 10 + '0';
    int delete = 0;
    int j = 0;

    nb = my_getstr(unity);
    nb2 = array_decimal(nb2, decimal_flow, delete);
    my_putstr(nb);
    my_putchar('.');
    my_putstr(nb2);
    return (0);
}
