/*
** EPITECH PROJECT, 2021
** move_entity.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void move_bullet(rpg_t *rpg_tab)
{
    sfTime time_move = sfClock_getElapsedTime(rpg_tab->gbl_clock);
    float seconds_move = time_move.microseconds / 1000000.0;
    float speed = speed_coeff(seconds_move - rpg_tab->g->gunshot_list->
    previous_clock, 1);

    for (int i = 0; i < rpg_tab->g->gunshot_list->nb_node; i++,
    rpg_tab->g->gunshot_node = rpg_tab->g->gunshot_node->next) {
        rpg_tab->g->gunshot_node->button->sprite_pos.x +=
        rpg_tab->g->gunshot_node->speed_bullet.x * speed;
        rpg_tab->g->gunshot_node->button->sprite_pos.y +=
        rpg_tab->g->gunshot_node->speed_bullet.y * speed;
        rpg_tab->g->gunshot_node->hitbox_bullet = (sfFloatRect) {rpg_tab->g->
        gunshot_node->button->sprite_pos.x,
        rpg_tab->g->gunshot_node->button->sprite_pos.y,
        rpg_tab->g->gunshot_node->button->sprite_rect.width,
        rpg_tab->g->gunshot_node->button->sprite_rect.height};
    }
    rpg_tab->g->gunshot_node = rpg_tab->g->gunshot_list->first;
    rpg_tab->g->gunshot_list->previous_clock =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
}

void move_guy(rpg_t *rpg_tab, int coeff, int top, int x_y)
{
    sfTime time_move = sfClock_getElapsedTime(rpg_tab->gbl_clock);
    float seconds_move = time_move.microseconds / 1000000.0;
    float speed = speed_coeff(seconds_move - rpg_tab->g->perso->previous_clock,
    rpg_tab->g->perso->speed);

    if (x_y == 0) {
        if (rpg_tab->keys->nb_pressed == 2) {
            rpg_tab->g->perso->guy->sprite_pos.x += (speed / 1.5) * coeff;
        } else
            rpg_tab->g->perso->guy->sprite_pos.x += speed * coeff;
        rpg_tab->g->perso->slide_effect = (sfVector2f) {(speed / 2) * coeff, 0};
    } else {
        if (rpg_tab->keys->nb_pressed == 2) {
            rpg_tab->g->perso->guy->sprite_pos.y += (speed / 1.5) * coeff;
        } else
            rpg_tab->g->perso->guy->sprite_pos.y += speed * coeff;
        rpg_tab->g->perso->slide_effect = (sfVector2f) {0, (speed / 2) * coeff};
    }
    rpg_tab->g->perso->guy->sprite_rect.top = top;
}