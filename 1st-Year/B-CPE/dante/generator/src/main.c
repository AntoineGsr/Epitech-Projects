/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** generator
*/

#include "../include/generator.h"

int main(int ac, char **av)
{
    generator *gen = NULL;

    if (error_input(ac, av) != 0)
        return (84);
    srand(time(NULL));
    gen = create_struct(ac, av);
    if (gen == NULL)
        return (84);
    create_map(gen->av1, gen->av2, gen);
    destroy_struct(gen);
    return (0);
}