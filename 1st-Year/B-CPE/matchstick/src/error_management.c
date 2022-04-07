/*
** EPITECH PROJECT, 2021
** error_management.c
** File description:
** duo_stumper
*/

#include "../include/matchstick.h"

int error_gestion(int ac, char **av)
{
    if (ac != 3) {
        my_putstr_error("Give 2 positives numbers as arguments\n");
        return (84);
    }
    if (my_getnbr(av[1]) == 0 || my_getnbr(av[2]) == 0) {
        my_putstr_error("The arguments must be greater than 0\n");
        return (84);
    }
    for (int i = 1; i != 3; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] < '0' || av[i][j] > '9') {
                my_putstr_error("Give 2 positives numbers as arguments\n");
                return (84);
            }
        }
    }
    return (0);
}