/*
** EPITECH PROJECT, 2020
** error_gestion.c
** File description:
** 105torus
*/

#include "105torus.h"

int error_gestion(int ac, char **av)
{
    int dot = 0;

    if (ac != 8)
        exit(84);
    if ((av[1][0] < '1' || av[1][0] > '3') || av[1][1] != '\0')
        exit(84);
    if (av[7][0] == '0' && av[7][1] == '\0')
        exit(84);
    for (int i = 2; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '+')
                exit(84);
            if (av[i][j] == '.')
                dot++;
            if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '.' && av[i][0] != '-')
                exit(84);
        }
        if (dot > 1)
            exit(84);
        dot = 0;
    }
}