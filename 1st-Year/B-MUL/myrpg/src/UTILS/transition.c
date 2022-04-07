/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void start_transition(rpg_t *rpg_tab)
{
    rpg_tab->u->transi_state = TRANSI_YES;
    sfClock_restart(rpg_tab->u->transi_black->anim_clock);
    rpg_tab->u->transi_x = 0;
}

void handle_transition_two(rpg_t *rpg_tab)
{
    sfSprite_setPosition(rpg_tab->u->transi_black->sprite,
    rpg_tab->main_cam_pos);
    sfRenderWindow_drawSprite(rpg_tab->window,
    rpg_tab->u->transi_black->sprite, NULL);
}

void handle_transition(rpg_t *rpg_tab)
{
    if (rpg_tab->u->transi_state == TRANSI_YES) {
        int fade_a;
        rpg_tab->u->transi_black->anim_time =
        sfClock_getElapsedTime(rpg_tab->u->transi_black->anim_clock);
        if (rpg_tab->u->transi_black->anim_time.microseconds
        / 1000000.0 > 0.0375) {
            fade_a = sin(rpg_tab->u->transi_x / 32) * 255;
            if (fade_a < 0) {
                rpg_tab->u->transi_x = 0;
                rpg_tab->u->transi_state = TRANSI_NO;
                return;
            } rpg_tab->u->transi_x += 1 * rpg_tab->coeff;
            if (rpg_tab->u->transi_state == TRANSI_YES) {
                sfSprite_setColor(rpg_tab->u->transi_black->sprite,
                (sfColor){0, 0, 0, fade_a});
            }
        } handle_transition_two(rpg_tab);
    }
}