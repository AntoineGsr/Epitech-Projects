/*
** EPITECH PROJECT, 2021
** error_gestion.c
** File description:
** generator
*/

#include "../include/generator.h"

int error_input(int ac, char **av)
{
    if (ac > 4 || ac < 3)
        return (84);
    if (ac == 4) {
        if (my_strcmp("perfect", av[3]) != 0)
            return (84);
    }
    if (my_getnbr(av[1]) <= 0 || my_getnbr(av[2]) <= 0)
        return (84);
    for (int i = 1; i < 3; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                return (84);
        }
    }
    return (0);
}