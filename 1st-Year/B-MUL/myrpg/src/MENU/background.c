/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void decal_rect_bg(sfIntRect *rect, int dec, int max)
{
    int lat_repeat = -1;
    int tmp_dec = dec;
    for (lat_repeat = -1; max / tmp_dec >= 1;) {
        tmp_dec = tmp_dec + max;
        lat_repeat++;
    }
    for (int i = 0; i < lat_repeat; i++) {
        (*rect).top += 720;
        if ((*rect).top >= 2100) {
            (*rect).top = 0;
        }
    } if ((*rect).left + dec >= max) {
        (*rect).top += 720;
        if ((*rect).top >= 2100) {
            (*rect).top = 0;
        }
        (*rect).left = dec - (max - (*rect).left);
    } else (*rect).left += dec;
}

void background_defil(rpg_t *rpg_tab)
{
    sfSprite_setPosition(rpg_tab->m->menu_gif->sprite, (sfVector2f) {0, 0});
    rpg_tab->m->menu_gif->anim_time =
    sfClock_getElapsedTime(rpg_tab->m->menu_gif->anim_clock);
    if (rpg_tab->m->menu_gif->anim_time.microseconds / 1000000.0 > 0.02) {
        decal_rect_bg(&(rpg_tab->m->menu_gif->sprite_rect), 1280
        * rpg_tab->int_coeff, 7680);
        sfSprite_setTextureRect(rpg_tab->m->menu_gif->sprite,
        rpg_tab->m->menu_gif->sprite_rect);
        sfClock_restart(rpg_tab->m->menu_gif->anim_clock);
    }
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->m->menu_gif->sprite,
    NULL);
}

void background_defil_param(rpg_t *rpg_tab)
{
    sfView_setCenter(rpg_tab->view, (sfVector2f){960, 540});
    sfRenderWindow_setView(rpg_tab->window, rpg_tab->view);
    sfSprite_setPosition(rpg_tab->m->menu_gif->sprite, (sfVector2f) {0, 0});
    rpg_tab->m->menu_gif->anim_time =
    sfClock_getElapsedTime(rpg_tab->m->menu_gif->anim_clock);
    if (rpg_tab->m->menu_gif->anim_time.microseconds / 1000000.0 > 0.02) {
        decal_rect_bg(&(rpg_tab->m->menu_gif->sprite_rect), 1280
        * rpg_tab->int_coeff, 7680);
        sfSprite_setTextureRect(rpg_tab->m->menu_gif->sprite,
        rpg_tab->m->menu_gif->sprite_rect);
        sfClock_restart(rpg_tab->m->menu_gif->anim_clock);
    }
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->m->menu_gif->sprite,
    NULL);
}