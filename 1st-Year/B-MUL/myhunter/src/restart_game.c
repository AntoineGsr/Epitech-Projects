/*
** EPITECH PROJECT, 2020
** restart_game.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

int restart_game(sfRenderWindow *window, sfEvent event,
S_base *menu, S_base *bird)
{
    int restart = 0;
    B_base bck;

    init_struct_back(&bck, "./src/endgame.jpg");
    sfSprite_setTexture(bck.sprite, bck.texture, sfTrue);
    restart = display_menu(window, &bck, event, menu);
    if (restart == 1) {
        return (0);
    } else {
        sfClock_restart(bird[0].clock);
        return (1);
    }
}