/*
** EPITECH PROJECT, 2021
** destroy_all.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void destroy_all(game_object ***sprite, list ***gbl, l_list ***node,
sfRenderWindow *window)
{
    sfMusic_destroy((*sprite)[0]->musics);
    for (int j = 0; j < (*gbl)[0]->max_node; j++,
        (*node)[0] = (*node)[0]->next) {
        sfSound_destroy((*node)[0]->mob->sound);
        sfSoundBuffer_destroy((*node)[0]->mob->soundbuffer);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_destroy(window);
}