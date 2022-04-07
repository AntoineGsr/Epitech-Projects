/*
** EPITECH PROJECT, 2020
** error_gestion.c
** File description:
** 102architect
*/

#include "102architect.h"

void calcul_theo_arg(int *theoric, char *av)
{
    if (av[0] == '-') {
        if (av[1] == 't') {
            *theoric += 3;
            if (av[2] != '\0')
                exit(84);
        }
        if (av[1] == 'z') {
            *theoric += 3;
            if (av[2] != '\0')
                exit(84);
        }
        if (av[1] == 'r') {
            *theoric += 2;
            if (av[2] != '\0')
                exit(84);
        }
        if (av[1] == 's') {
            *theoric += 2;
            if (av[2] != '\0')
                exit(84);
        }
    }
}

int error_gestion(int ac, char **av)
{
    int dot = 0;
    int theoric = 3;

    if (ac == 1)
        exit(84);
    for (int i = 1; i < ac; i++) {
        if (i >= 3)
            calcul_theo_arg(&theoric, av[i]);
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '+')
                exit(84);
            if (av[i][j] == '.')
                dot++;
            if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '.' &&
                av[i][0] != '-' && av[i] != "-t" && av[i] != "-z"
                && av[i] != "-r" && av[i] != "-s")
                exit(84);
        }
        if (dot > 1)
            exit(84);
        dot = 0;
    }
    if (theoric != ac)
        exit(84);
    return (0);
}
