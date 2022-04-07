/*
** EPITECH PROJECT, 2020
** error_gestion.c
** File description:
** my_runner
*/

#include "my_runner.h"

int error_gestion(int ac, char **av)
{
    int opn = 0;

    opn = open(av[1], O_RDONLY);
    if (ac != 2 || (opn == -1 && av[1][0] != '-' && av[1][1] != 'h')) {
        my_putstr_fast("./my_runner: bad arguments: ");
        my_put_nbr(ac - 1);
        my_putstr_fast(" given but 1 is required\nretry with -h\n");
        return (-1);
    }
    return (0);
}