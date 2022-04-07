/*
** EPITECH PROJECT, 2020
** helper.c
** File description:
** navy
*/

#include "navy.h"

int helper(int ac, char **av)
{
    int fd = 0;
    char buff[204];

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        fd = open("helper.txt", O_RDONLY);
        read(fd, buff, 203);
        buff[203] = '\0';
        my_putstr_fast(buff);
        my_putchar('\n');
        return (0);
    }
    return (1);
}