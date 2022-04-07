/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** lib
*/

#include "my.h"

int neg_pos(char *str)
{
    int neg = 0;
    int i = 0;

    for (i; str[i] != '\0' && str[i] != '-' && str[i] != '+'
        && (str[i] < '0' || str[i] > '9'); i++);
    for (i; str[i] != '\0' && (str[i] == '-' || str[i] == '+')
        && (str[i] < '0' || str[i] > '9'); i++)
        neg += 1;
    if (neg % 2 != 0)
        return (-1);
    return (1);
}

int my_getnbr(char *str)
{
    int nb = 0;
    int neg = 0;
    int i = 0;

    neg = neg_pos(str);
    for (i; str[i] != '\0' && (str[i] < '0' || str[i] > '9'); i++);
    for (i; str[i] >= '0' && str[i] <= '9'; i++) {
        nb = nb * 10 + (str[i] - '0');
    }
    return (nb * neg);
}
