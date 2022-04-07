/*
** EPITECH PROJECT, 2020
** count_nb_args.c
** File description:
** pushswap
*/

#include "pushswap.h"

int count_nb_args(int ac, char **av)
{
    int max = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' || (av[i][0] >= '0' && av[i][0] <= '9')) {
            max += 1;
        }
    }
    if (max < (ac - 1))
        return (0);
    return (max);
}
