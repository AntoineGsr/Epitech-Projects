/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** lib
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    for (nb; nb <= 2147483647; nb++) {
        if (my_is_prime(nb) == 1) {
            return (nb);
        }
    }
    return (0);
}
