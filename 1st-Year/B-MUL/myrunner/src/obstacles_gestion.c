/*
** EPITECH PROJECT, 2020
** obstacles_gestion.c
** File description:
** my_runner
*/

#include "my_runner.h"

void display_obstacles(l_list **obstacles, sfRenderWindow *window)
{
    if ((*obstacles)->obs == 3) {
        if ((*obstacles)->rect.left < 360) {
            (*obstacles)->rect.left += 40;
        } else
            (*obstacles)->rect.left = 0;
    }
    if ((*obstacles)->obs >= 2) {
        sfSprite_setTexture((*obstacles)->sprite, (*obstacles)->texture,
        sfTrue);
        sfSprite_setTextureRect((*obstacles)->sprite, (*obstacles)->rect);
        sfSprite_setPosition((*obstacles)->sprite, (*obstacles)->pos);
        sfRenderWindow_drawSprite(window, (*obstacles)->sprite, NULL);
    }
}

void hit_spike_coin_portal(list **gbl, l_list **obstacles, enum pages *state,
game_object ***sprite)
{
    float posx = (*sprite)[16]->pos.x;
    float obs_x = (*obstacles)->pos.x;
    l_list *stock = malloc(sizeof(l_list));

    stock = (*obstacles)->next;
    if (((*sprite)[16]->pos.y + 81 >= 986)
        && ((posx >= obs_x && posx <= obs_x + 80)
        || (posx + 65 >= obs_x && posx + 65 <= obs_x + 80))) {
        if ((*obstacles)->obs == 2)
            (*sprite)[16]->life -= 1;
        if ((*obstacles)->obs == 3) {
            update_coin_sound(gbl, obstacles, sprite);
            destroy_coin(gbl, obstacles, stock);
        }
    }
}

void verif_win_game(list **gbl, l_list **obstacles, enum pages *state,
game_object ***sprite)
{
    float posx = (*sprite)[16]->pos.x;
    float obs_x = (*obstacles)->pos.x;

    if (posx + 50 >= obs_x) {
        if ((*obstacles)->obs == 4)
            *state = GAMEWIN;
    }
}

void reaction_obstacles(list **gbl, l_list **obstacles, enum pages *state,
game_object ***sprite)
{
    float posx = (*sprite)[16]->pos.x;
    float obs_x = (*obstacles)->pos.x;

    if ((*state < GAME && (*gbl)->first_pos == 1)
        || (*sprite)[16]->restart_press == 1)
        restart_obstacles(gbl, obstacles, state, sprite);
    if ((*state >= GAME && *state <= PAUSE) && (*gbl)->first_pos == 1) {
        for (int i = 0; (*obstacles) != NULL && i < (*gbl)->nb_obs
            && (*obstacles)->obs != 5 && (*sprite)[16]->life > 0; i++) {
            if ((*sprite)[16]->pos.y + 81 >= 986)
                hit_spike_coin_portal(gbl, obstacles, state, sprite);
            verif_win_game(gbl, obstacles, state, sprite);
            if ((*sprite)[16]->life <= 0 && *state != GAMEWIN)
                *state = GAMEOVER;
            (*obstacles) = (*obstacles)->next;
            obs_x = (*obstacles)->pos.x;
        }
        (*obstacles) = (*gbl)->first;
    }
}

void obstacles_gestion(list **gbl, l_list **obstacles, enum pages *state,
sfRenderWindow *window)
{
    if (*state >= GAME && *state <= PAUSE) {
        for (int i = 0; i < (*gbl)->nb_obs && (*obstacles)->obs != 5; i++) {
            if ((*gbl)->first_pos == 0) {
                (*obstacles)->pos.x = i * 80;
            } else {
                (*obstacles)->pos.x += (*gbl)->speed;
            }
            display_obstacles(obstacles, window);
            if ((*obstacles)->pos.x < -100 && (*gbl)->nb_obs > 0) {
                destroy_under_map(gbl, obstacles);
            }
            (*obstacles) = (*obstacles)->next;
        }
        (*gbl)->first_pos = 1;
        (*obstacles) = (*gbl)->first;
    }
}