/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** istoa
*/

#include "my.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int my_nbr_len(int nb)
{
    int i;

    if (nb == 0)
        return (1);
    for (i = 0; nb != 0; i++)
        nb = nb / 10;
    return (i);
}

char *my_itoa(int num)
{
    int i;
    int rem;
    int len = 0;
    int n;
    if (num == 0) return ("0");
    char *str = malloc(sizeof(char) * my_nbr_len(num) + 1);
    n = num;
    while (n != 0) {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    } str[len] = '\0';
    return (str);
}