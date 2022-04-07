/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void animate_guy_thirteen(rpg_t *rpg_tab, float seconds)
{
    rpg_tab->g->perso->shooting = false;
    if (seconds > 0.04) {
        decal_rect_guy(&(rpg_tab->g->perso->guy->sprite_rect),
        rpg_tab->g->perso->guy->sprite_rect.width * rpg_tab->int_coeff,
        rpg_tab->g->perso->guy->sprite_rect.width * 12, 100);
        if (((rpg_tab->keys->mv_right == true && rpg_tab->keys->mv_left ==
        true) || (rpg_tab->keys->mv_up == true && rpg_tab->keys->mv_down ==
        true)) && rpg_tab->keys->nb_pressed == 2)
            rpg_tab->g->perso->guy->sprite_rect.left = 0;
        sfClock_restart(rpg_tab->g->perso->guy->anim_clock);
    }
}

void animate_guy_twelve(rpg_t *rpg_tab, float seconds_weapon)
{
    if (rpg_tab->g->perso->target == true) {
        for (int i = 0; i < 5; i++) {
            if (animate_guy_two(rpg_tab, i) == 1) break;
            if (animate_guy_three(rpg_tab, i) == 1) break;
        }
    } animate_guy_eleven(rpg_tab, seconds_weapon);
}

void animate_guy_eleven(rpg_t *rpg_tab, float seconds_weapon)
{
    animate_guy_four(rpg_tab);
    animate_guy_five(rpg_tab);
    animate_guy_eight(rpg_tab, seconds_weapon);
    if (rpg_tab->g->perso->shooting == true
    && rpg_tab->g->perso->target == true && rpg_tab->g->perso->weapon == 2
    && seconds_weapon > 0.05) {
        if (rpg_tab->g->perso->guy->sprite_rect.left == 400) {
            sfIntRect bullet = (sfIntRect){0, 0, 20, 8};
            animate_guy_nine(rpg_tab, &bullet);
            animate_guy_ten(rpg_tab);
        } decal_rect_guy(&(rpg_tab->g->perso->guy->sprite_rect),
        rpg_tab->g->perso->guy->sprite_rect.width * rpg_tab->int_coeff,
        rpg_tab->g->perso->guy->sprite_rect.width * 9, 0);
        if (rpg_tab->g->perso->guy->sprite_rect.left >= 800) {
            rpg_tab->g->perso->shooting = false;
            rpg_tab->g->perso->guy->sprite_rect.left = 400;
        } sfClock_restart(rpg_tab->g->perso->weapon_clock);
    }
    smooth_effect(rpg_tab);
}