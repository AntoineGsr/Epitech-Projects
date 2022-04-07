/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void animate_guy_five(rpg_t *rpg_tab)
{
    if (rpg_tab->g->perso->weapon == 1
    && rpg_tab->g->perso->guy->sprite_rect.left > 300)
        rpg_tab->g->perso->guy->sprite_rect.left = 0;
    if (rpg_tab->g->perso->weapon == 2
    && rpg_tab->g->perso->guy->sprite_rect.left < 400)
        rpg_tab->g->perso->guy->sprite_rect.left = 400;
}

void animate_guy_four(rpg_t *rpg_tab)
{
    if (rpg_tab->g->perso->shooting == false
        || rpg_tab->g->perso->weapon == 0) {
            rpg_tab->g->perso->guy->sprite_rect.left = 0;
        }
        if (rpg_tab->g->perso->weapon == 0
        && rpg_tab->g->perso->guy->sprite_rect.top >= 400) {
            rpg_tab->g->perso->guy->sprite_rect.top -= 400;
        }
        if (rpg_tab->g->perso->weapon >= 1
        && rpg_tab->g->perso->guy->sprite_rect.top < 400) {
            rpg_tab->g->perso->guy->sprite_rect.top += 400;
            if (rpg_tab->g->perso->shooting == false
            && rpg_tab->g->perso->weapon == 1)
                rpg_tab->g->perso->guy->sprite_rect.left = 0;
            if (rpg_tab->g->perso->shooting == false
            && rpg_tab->g->perso->weapon == 2)
                rpg_tab->g->perso->guy->sprite_rect.left = 400;
        }
}

int animate_guy_three(rpg_t *rpg_tab, int i)
{
    if (sfFloatRect_intersects(&(rpg_tab->u->c_box),
    &(rpg_tab->g->perso->shoot_area->south[i]), NULL) == sfTrue) {
        rpg_tab->g->perso->guy->sprite_rect.top = 300;
        rpg_tab->g->perso->shoot_area->orientation_left =
        SOUTH_LEFT;
        rpg_tab->g->perso->shoot_area->orientation_top = SOUTH_TOP;
        return (1);
    }
    if (sfFloatRect_intersects(&(rpg_tab->u->c_box),
    &(rpg_tab->g->perso->shoot_area->west[i]), NULL) == sfTrue) {
        rpg_tab->g->perso->guy->sprite_rect.top = 100;
        rpg_tab->g->perso->shoot_area->orientation_left = WEST_LEFT;
        rpg_tab->g->perso->shoot_area->orientation_top = WEST_TOP;
        return (1);
    } return (0);
}

int animate_guy_two(rpg_t *rpg_tab, int i)
{
    if (sfFloatRect_intersects(&(rpg_tab->u->c_box),
    &(rpg_tab->g->perso->shoot_area->north[i]), NULL) == sfTrue) {
        rpg_tab->g->perso->guy->sprite_rect.top = 200;
        rpg_tab->g->perso->shoot_area->orientation_left =
        NORTH_LEFT;
        rpg_tab->g->perso->shoot_area->orientation_top = NORTH_TOP;
        return (1);
    }
    if (sfFloatRect_intersects(&(rpg_tab->u->c_box),
    &(rpg_tab->g->perso->shoot_area->east[i]), NULL) == sfTrue) {
        rpg_tab->g->perso->guy->sprite_rect.top = 0;
        rpg_tab->g->perso->shoot_area->orientation_left = EAST_LEFT;
        rpg_tab->g->perso->shoot_area->orientation_top = EAST_TOP;
        return (1);
    } return (0);
}

void animate_guy(rpg_t *rpg_tab)
{
    sfTime time = sfClock_getElapsedTime(rpg_tab->g->perso->guy->anim_clock);
    float seconds = time.microseconds / 1000000.0;
    sfTime time_weapon = sfClock_getElapsedTime
    (rpg_tab->g->perso->weapon_clock);
    float seconds_weapon = time_weapon.microseconds / 1000000.0;
    if (rpg_tab->g->perso->weapon == 2 && rpg_tab->g->nb_bullet <= 0)
        rpg_tab->g->perso->shooting = false;
    if (rpg_tab->g->perso->weapon == 0 || rpg_tab->g->perso->target == false)
        rpg_tab->g->perso->shooting = false;
    if ((rpg_tab->keys->mv_right == false && rpg_tab->keys->mv_left == false
    && rpg_tab->keys->mv_up == false && rpg_tab->keys->mv_down == false)
    || rpg_tab->g->perso->hit == 1) {
        animate_guy_twelve(rpg_tab, seconds_weapon);
    } else {
        animate_guy_thirteen(rpg_tab, seconds);
    }
}