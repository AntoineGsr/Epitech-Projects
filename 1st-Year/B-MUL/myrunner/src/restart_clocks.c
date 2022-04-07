/*
** EPITECH PROJECT, 2021
** restart_clocks.c
** File description:
** my_runner
*/

#include "my_runner.h"

void restart_obstacles(list **gbl, l_list **obstacles, enum pages *state,
game_object ***sprite)
{
    int ac = (*gbl)->ac;
    char **av = malloc(sizeof(char *) * 2);

    for (int i = 0; i < 2; i++) {
        av[i] = malloc(sizeof(char) * my_strlen((*gbl)->av));
        av[i][0] = '\0';
    }
    av[1] = (*gbl)->av;
    destroy_obstacles(gbl, obstacles);
    *gbl = create_obstacles(ac, av, obstacles);
    (*sprite)[16]->restart_press = 0;
}

void restart_clocks(game_object **sprite)
{
    for (int i = 0; i < 8; i++) {
        sfClock_restart(sprite[i]->clock);
        sfClock_restart(sprite[i + 8]->clock);
    }
    sfClock_restart(sprite[16]->clock);
}
