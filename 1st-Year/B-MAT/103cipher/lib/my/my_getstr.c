/*
** EPITECH PROJECT, 2020
** my_getstr.c
** File description:
** lib
*/

#include "my.h"
#include <stdlib.h>

int negative(int nb, int size)
{
    int neg = 0;

    if (nb < 0) {
        nb = nb * (-1);
        size = nb;
        neg = 1;
    }
    return (size);
}

char *str_creation(int nb, int count, int i, char *str)
{
    if (nb == 0) {
        str = malloc(sizeof(char) * 2);
        str[0] = '0';
        str[1] = '\0';
        return (str);
    } else if (nb < 0) {
        str = malloc(sizeof(char) * (count + 2));
        str[0] = '-';
        count = count + 1;
        nb = nb * (-1);
    } else
        str = malloc(sizeof(char) * (count + 1));
    i = count - 1;
    for (i; nb > 0; i--) {
        str[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    str[count] = '\0';
    return (str);
}

char *my_getstr(int nb)
{
    int size = nb;
    int count = 0;
    int i = 0;
    int neg = 0;
    char *str = NULL;

    size = negative(nb, size);
    if (nb == 0) {
        str = malloc(sizeof(char) * 2);
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    while (size > 0) {
        size = size / 10;
        count++;
    }
    str = str_creation(nb, count, i, str);
    return (str);
}
