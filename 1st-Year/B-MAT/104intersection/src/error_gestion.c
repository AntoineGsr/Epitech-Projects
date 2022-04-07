/*
** EPITECH PROJECT, 2020
** error_gestion.c
** File description:
** 104intersection
*/

#include "104intersection.h"

int error_gestion(int ac, char **av)
{
    int dot = 0;

    if (ac != 9)
        exit(84);
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[1][0] != '1' && av[1][0] != '2' && av[1][0] != '3')
                exit(84);
            if (av[1][1] != '\0')
                exit(84);
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
    if (atof(av[8]) <= 0 && (atof(av[1]) == 1 || atof(av[1]) == 2))
        exit(84);
    if (atof(av[8]) == 0 && atof(av[1]) == 3)
        exit(84);
    if (atof(av[5]) == 0 && atof(av[6]) == 0 && atof(av[7]) == 0)
        exit(84);
}