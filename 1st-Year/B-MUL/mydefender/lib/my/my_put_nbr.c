/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** lib
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + 48);
    return (0);
}
