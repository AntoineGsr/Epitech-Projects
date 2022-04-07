/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    rpg_t *rpg_tab = malloc(sizeof(rpg_t));
    generator *gen = NULL;

    get_seed();
    gen = create_struct(ac, av);
    if (gen == NULL)
        return (84);
    rpg_tab->maze_dante = create_map(gen->av1, gen->av2, gen);
    init_base(rpg_tab);
    create_tile(rpg_tab);
    game_loop(rpg_tab);
    destroy_all(rpg_tab);
    destroy_struct(gen);
    return (0);
}