/*
** EPITECH PROJECT, 2020
** helper_func.c
** File description:
** 103cipher
*/

#include "103cipher.h"

int helper_func(int ac, char **av)
{
    int fd = 0;
    char *buff[214];

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        fd = open("helper.txt", O_RDONLY);
        read(fd, buff, 213);
        printf("%s\n", buff);
        return (0);
    }
    return (1);
}
