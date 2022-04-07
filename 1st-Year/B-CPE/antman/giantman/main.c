/*
** EPITECH PROJECT, 2021
** main
** File description:
** principale function
*/

#include "function.h"

int main(int ac, char **av)
{
    giantman *use = malloc(sizeof(giantman));

    if (ac != 3 || other_error(av, use) == 84)
        return (84);
    if (av[2][0] != '1')
        return (0);
    use_set(use, av);
    my_giantman(use);
    return (0);
}