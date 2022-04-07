/*
** EPITECH PROJECT, 2021
** helper.c
** File description:
** sokoban
*/

#include "../include/sokoban.h"

int helper(int ac, char **av)
{
    int opn = 0;
    char buff[186];

    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        opn = open("helper.txt", O_RDONLY);
        if (opn == -1)
            return (-1);
        read(opn, buff, 185);
        buff[185] = '\0';
        my_putstr(buff);
        my_putchar('\n');
        return (1);
    }
    return (0);
}