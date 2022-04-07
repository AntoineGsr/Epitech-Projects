/*
** EPITECH PROJECT, 2020
** my_isneg.c
** File description:
** lib
*/

#include "my.h"

int my_isneg(int nb)
{
    if (nb >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
