/*
** EPITECH PROJECT, 2020
** error management
** File description:
** file 1
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int print_error(int index)
{
    if (index == 1)
        fprintf(stderr, "SYNTAX ERROR : TOO FEW ARGUMENT\n");
    if (index == 2)
        fprintf(stderr, "SYNTAX ERROR : TOO MANY ARGUMENTS\n");
    if (index == 3)
        fprintf(stderr, "SYNTAX ERROR :  BAD ARGUMENTS\n");
    fprintf(stderr, "make './101pong -h' for more information\n");
    return (84);
}

int is_nb(int ac, char **av)
{
    int dot = 0;

    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '+')
                return (1);
            if (av[i][j] == '.')
                dot++;
            if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '.' && av[i][j] != '-')
                return (1);
        }
        if (dot > 1)
            return (1);
        dot = 0;
    }
    for (int i = 0; av[7][i] != '\0'; i++) {
        if (av[7][i] < '0' || av[7][i] > '9')
            return (1);
    }
    return (0);
}

int error_management(int ac, char **av)
{
    if (ac < 8) {
        print_error(1);
        return (0);
    }
    if (ac > 8) {
        print_error(2);
        return (0);
    }
    if (is_nb(ac, av) == 1) {
        print_error(3);
        return (0);
    }
    return (1);
}
