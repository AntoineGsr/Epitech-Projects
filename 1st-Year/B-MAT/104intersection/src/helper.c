/*
** EPITECH PROJECT, 2020
** helper.c
** File description:
** 104intersection
*/

#include "104intersection.h"

int helper(int ac, char **av)
{
    int opn = 0;
    char buff[403];

    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        opn = open("helper.txt", O_RDONLY);
        if (opn == -1)
            return (-1);
        read(opn, buff, 402);
        buff[402] = '\0';
        my_putstr_fast(buff);
        my_putchar('\n');
        exit(0);
    }
    return (0);
}
