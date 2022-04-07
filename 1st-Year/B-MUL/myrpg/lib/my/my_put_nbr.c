/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** put nbr
*/

#include "my.h"

int my_put_nbr(int nombre)
{
    int unite;

    if (nombre < 0)
    {
        if (nombre != -2147483648) {
            nombre = nombre * (-1);
            my_putchar('-');
        } else {
            my_putchar('-');
            my_putchar('2');
            my_put_nbr(147483648);
            return (0);
        }
    } if (nombre >= 10) {
        unite = (nombre % 10);
        nombre = (nombre - unite) / 10;
        my_put_nbr(nombre);
        my_putchar(48 + unite);
    } else
        my_putchar(48 + nombre % 10);
    return (0);
}