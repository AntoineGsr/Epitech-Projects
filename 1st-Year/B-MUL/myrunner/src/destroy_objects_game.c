/*
** EPITECH PROJECT, 2021
** destroy_objects_game.c
** File description:
** my_runner
*/

#include "my_runner.h"

void destroy_coin(list **gbl, l_list **obstacles, l_list *stock)
{
    if ((*obstacles)->obs >= 2 && (*obstacles)->obs < 5) {
        sfTexture_destroy((*obstacles)->texture);
        sfSprite_destroy((*obstacles)->sprite);
    }
    (*gbl)->first = (*obstacles)->next;
    (*obstacles)->next = NULL;
    (*obstacles)->previous = NULL;
    free(*obstacles);
    (*obstacles) = malloc(sizeof(l_list));
    (*obstacles) = stock;
}

void destroy_objects_game(game_object ***sprite, sfRenderWindow *window)
{
    sfMusic_destroy((*sprite)[16]->my_music1);
    sfMusic_destroy((*sprite)[16]->my_music2);
    sfMusic_destroy((*sprite)[16]->my_sound_effect);
    for (int i = 0; i < 20; i++) {
        destroy_object((*sprite)[i]);
    }
    free(*sprite);
}

void destroy_under_map(list **gbl, l_list **obstacles)
{
    if ((*obstacles)->obs >= 2 && (*obstacles)->obs < 5) {
        sfTexture_destroy((*obstacles)->texture);
        sfSprite_destroy((*obstacles)->sprite);
    }
    (*gbl)->first = (*obstacles)->next;
    (*obstacles)->next = NULL;
    (*obstacles)->previous = NULL;
    free(*obstacles);
    (*obstacles) = malloc(sizeof(l_list));
    (*obstacles) = (*gbl)->first;
    (*gbl)->nb_obs -= 1;
}

void destroy_obstacles(list **gbl, l_list **obstacles)
{
    while ((*gbl)->first != NULL) {
        destroy_under_map(gbl, obstacles);
    }
    free(*gbl);
}

void destroy_all_objects(game_object ***sprite, sfRenderWindow **window,
list **gbl, l_list **obstacles)
{
    destroy_objects_game(sprite, *window);
    destroy_obstacles(gbl, obstacles);
    sfRenderWindow_destroy(*window);
}