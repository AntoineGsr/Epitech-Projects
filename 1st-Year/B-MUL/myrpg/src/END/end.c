/*
** EPITECH PROJECT, 2021
** entity_gestion.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void decal_rect_end(rpg_t *rpg_tab, sfIntRect *rect, sfVector2f dec,
sfVector2f max)
{
    int lat_repeat = -1;
    int tmp_dec = dec.x;

    for (lat_repeat = -1; max.x / tmp_dec >= 1;) {
        tmp_dec = tmp_dec + max.x;
        lat_repeat++;
    }
    for (int i = 0; i < lat_repeat; i++) {
        (*rect).top += dec.y;
        if ((*rect).top >= max.y) {
            rpg_tab->step = END;
        }
    } if ((*rect).left + dec.x >= max.x) {
        (*rect).top += dec.y;
        if ((*rect).top >= max.y) {
            rpg_tab->step = END;
        } (*rect).left = dec.x - (max.x - (*rect).left);
    } else (*rect).left += dec.x;
}

void end_menu_anim(rpg_t *rpg_tab)
{
    sfView_setCenter(rpg_tab->view, (sfVector2f) {960, 540});
    sfRenderWindow_setView(rpg_tab->window, rpg_tab->view);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->eg->
    end_anim->sprite, NULL);
    rpg_tab->eg->end_anim->anim_time =
    sfClock_getElapsedTime(rpg_tab->eg->end_anim->anim_clock);
    if (rpg_tab->eg->end_anim->anim_time.microseconds / 1000000.0 > 0.0375) {
        sfClock_restart(rpg_tab->eg->end_anim->anim_clock);
        decal_rect_end(rpg_tab, &(rpg_tab->eg->end_anim->sprite_rect),
        (sfVector2f){728 * rpg_tab->int_coeff, 408},
        (sfVector2f){3640, 12648});
        sfSprite_setTextureRect(rpg_tab->eg->end_anim->sprite,
        rpg_tab->eg->end_anim->sprite_rect);
    }
}

void end_menu(rpg_t *rpg_tab)
{
    end_menu_anim(rpg_tab);
    while (sfRenderWindow_pollEvent(rpg_tab->window, &(rpg_tab->event))) {
        if (rpg_tab->event.type == sfEvtClosed) {
            sfRenderWindow_close(rpg_tab->window);
        }
    }
}