/*
** EPITECH PROJECT, 2021
** animation_plantes.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void restart_rect_plante(list ***gbl, l_list ***node, int *destroy_bomb)
{
    int can_destroy_bomb = 0;

    if ((*node)[0]->mob->rect.left >= (*node)[0]->mob->offset) {
        (*node)[0]->mob->rect.left = 0;
        if ((*node)[0]->mob->offset != (*node)[0]->mob->offset_origin) {
            (*node)[0]->mob->offset = (*node)[0]->mob->offset_origin;
            (*node)[0]->mob->rect.top = 0;
            can_destroy_bomb = 1;
        }
    }
    if (can_destroy_bomb == 1 && (*node)[0]->mob->type_plante == 4)
        *destroy_bomb = 1;
}

void have_to_animate_plante(list ***gbl, l_list ***node, int *destroy_bomb)
{
    float seconds = 0;

    (*node)[0]->mob->time = sfClock_getElapsedTime((*node)[0]->mob->clock);
    seconds = (*node)[0]->mob->time.microseconds / 1000000.0;
    if (seconds > (*node)[0]->mob->animation_time
        && (*node)[0]->mob->type_plante != 6) {
        (*node)[0]->mob->rect.left += (*node)[0]->mob->rect.width;
        restart_rect_plante(gbl, node, destroy_bomb);
        if ((*node)[0]->mob->type_plante == 4) {
            if ((*node)[0]->mob->rect.left > 0) {
                (*node)[0]->mob->animation_time = 0.15;
            } else
                (*node)[0]->mob->animation_time = 3;
        }
        sfClock_restart((*node)[0]->mob->clock);
    }
}

void have_destroy_bomb(list ***gbl, l_list ***node, int *destroy_bomb, int *i)
{
    *destroy_bomb = 0;
    (*gbl)[0]->map[(*node)[0]->pos_x_map][(*node)[0]->pos_y_map] = 0;
    sfSound_destroy((*node)[0]->mob->sound);
    sfSoundBuffer_destroy((*node)[0]->mob->soundbuffer);
    destroy_node_noloop(&(*gbl)[0], &(*node)[0], i);
}

void animation_plante(list ***gbl, l_list ***node, game_object ***sprite)
{
    float seconds = 0;
    int destroy_bomb = 0;

    for (int i = 0; i < (*gbl)[0]->max_node; i++,
    (*node)[0] = (*node)[0]->next) {
        have_to_animate_plante(gbl, node, &destroy_bomb);
        (*node)[0]->mob->time = sfClock_getElapsedTime
        ((*node)[0]->mob->clock_action);
        seconds = (*node)[0]->mob->time.microseconds / 1000000.0;
        if (seconds > (*node)[0]->mob->can_action)
            analyse_action(gbl, node, sprite);
        if ((*node)[0]->mob->have_to_shoot == 1) {
            (*node)[2] = add_to_list_bullet(&(*gbl)[2], node);
            (*node)[0]->mob->sound_effect = (*sprite)[0]->sound_effect;
            use_sound_effect(&(*node)[0]->mob);
        }
        if (destroy_bomb == 1)
            have_destroy_bomb(gbl, node, &destroy_bomb, &i);
    }
    (*node)[0] = (*gbl)[0]->first;
}