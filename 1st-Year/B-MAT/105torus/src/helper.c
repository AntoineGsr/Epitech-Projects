/*
** EPITECH PROJECT, 2020
** helper.c
** File description:
** 105torus
*/

#include "105torus.h"

int helper(int ac, char **av)
{
    int opn = 0;
    char buff[311];

    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        opn = open("helper.txt", O_RDONLY);
        if (opn == -1)
            return (-1);
        read(opn, buff, 310);
        buff[310] = '\0';
        my_putstr_fast(buff);
        my_putchar('\n');
        exit(0);
    }
    return (0);
}
