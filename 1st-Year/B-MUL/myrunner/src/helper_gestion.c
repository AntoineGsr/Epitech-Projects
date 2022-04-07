/*
** EPITECH PROJECT, 2020
** helper_gestion.c
** File description:
** my_runner
*/

#include "my_runner.h"

int helper_gestion(int ac, char **av)
{
    int opn = 0;
    char buff[1072];

    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        opn = open("helper.txt", O_RDONLY);
        if (opn == -1)
            return (-1);
        read(opn, buff, 1071);
        buff[1071] = '\0';
        my_putstr_fast(buff);
        my_putchar('\n');
        close(opn);
        return (-1);
    }
    if (av[1][0] == '-' && av[1][1] == 'i')
        return (-1);
    return (0);
}