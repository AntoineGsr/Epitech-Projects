/*
** EPITECH PROJECT, 2020
** exe_game.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

int exe_game(S_base *bird, B_base *bck, sfRenderWindow *window, sfEvent event)
{
    S_base *menu = malloc(sizeof(*menu));

    init_struct_back(bck, "./src/background.png");
    while (sfRenderWindow_isOpen(window) && bird[0].exit_button == 0
    && bird[0].life < 3) {
        analyse_events(bck, bird, window, event);
        moving_sprite_bird(bck, bird, window, bird[0].time =
        sfClock_restart(bird[0].clock));
        sfRenderWindow_clear(window, sfBlack);
        display_my_window(window, bck, bird, bird[0].time);
    }
    if (bird[0].life >= 3) {
        if (restart_game(window, event, menu, bird) == 1) {
            init_struct_sprite(bird, "./src/black_birdthibs.png",
            bird[0].nb_bird);
            exec_struct_bird(bird, bird[0].nb_bird);
            exe_game(bird, bck, window, event);
        }
    }
    return (0);
}
