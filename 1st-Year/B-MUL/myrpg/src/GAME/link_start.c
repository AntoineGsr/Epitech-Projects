/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void clean_log_text(rpg_t *rpg_tab)
{
    free(rpg_tab->g->log_wind->password->ctrl);
    rpg_tab->g->log_wind->password->ctrl = my_memset_char(26);
    free(rpg_tab->g->log_wind->nocrypt_password);
    rpg_tab->g->log_wind->nocrypt_password = my_memset_char(26);
    if (rpg_tab->g->play != LOAD_EXISTENT_GAME) {
        free(rpg_tab->g->log_wind->name->ctrl);
        rpg_tab->g->log_wind->name->ctrl = my_memset_char(26);
    }
}

void decal_rect_link(rpg_t *rpg_tab, sfIntRect *rect, sfVector2f dec,
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
            if (rpg_tab->g->play == LOAD_EXISTENT_GAME) {
                rpg_tab->g->link_start_state = LOG_PSWD;
            } else
                rpg_tab->g->link_start_state = LOG_NAME;
        }
    } if ((*rect).left + dec.x >= max.x) {
        (*rect).top += dec.y;
        if ((*rect).top >= max.y) {
            if (rpg_tab->g->play == LOAD_EXISTENT_GAME) {
                rpg_tab->g->link_start_state = LOG_PSWD;
            } else
                rpg_tab->g->link_start_state = LOG_NAME;
        } (*rect).left = dec.x - (max.x - (*rect).left);
    } else (*rect).left += dec.x;
}

void link_start_handling(rpg_t *rpg_tab)
{
    if (rpg_tab->g->link_start_state == LINK_NOT_DONE) {
        sfSprite_setPosition(rpg_tab->g->link_start_sprite->sprite,
        rpg_tab->main_cam_pos);
        rpg_tab->g->link_start_sprite->anim_time =
        sfClock_getElapsedTime(rpg_tab->g->link_start_sprite->anim_clock);
        if (rpg_tab->g->link_start_sprite->
        anim_time.microseconds / 1000000.0 > 0.0375) {
            sfClock_restart(rpg_tab->g->link_start_sprite->anim_clock);
            decal_rect_link(rpg_tab, &(rpg_tab->g->link_start_sprite->
            sprite_rect), (sfVector2f){600 * rpg_tab->int_coeff, 338},
            (sfVector2f){6000, 6760});
            sfSprite_setTextureRect(rpg_tab->g->link_start_sprite->sprite,
            rpg_tab->g->link_start_sprite->sprite_rect);
        }
        if (rpg_tab->g->link_start_state != LINK_NOT_DONE) {
            rpg_tab->g->link_start_sprite->sprite_rect.top = 6422;
            rpg_tab->g->link_start_sprite->sprite_rect.left = 1800;
            sfSprite_setTextureRect(rpg_tab->g->link_start_sprite->sprite,
            rpg_tab->g->link_start_sprite->sprite_rect);
        }
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->g->link_start_sprite->sprite, NULL);
    }
}