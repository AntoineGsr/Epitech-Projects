/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void decal_rect_guy(sfIntRect *rect, int dec, int max, int reset)
{
    int lat_repeat = -1;
    int tmp_dec = dec;

    for (lat_repeat = -1; max / tmp_dec >= 1;) {
        tmp_dec = tmp_dec + max;
        lat_repeat++;
    }
    if ((*rect).left + dec >= max) {
        (*rect).left = reset;
    } else (*rect).left += dec;
}

void smooth_effect(rpg_t *rpg_tab)
{
    sfTime time = sfClock_getElapsedTime(rpg_tab->g->perso->guy->anim_clock);
    float seconds = time.microseconds / 1000000.0;

    rpg_tab->g->perso->guy->sprite_pos.x += rpg_tab->g->perso->slide_effect.x;
    rpg_tab->g->perso->guy->sprite_pos.y += rpg_tab->g->perso->slide_effect.y;
    if (seconds > 0.15) {
        rpg_tab->g->perso->slide_effect.x = rpg_tab->g->
        perso->slide_effect.x / 2;
        if (fabs(rpg_tab->g->perso->slide_effect.x) < 0.1)
            rpg_tab->g->perso->slide_effect.x = 0;
        rpg_tab->g->perso->slide_effect.y = rpg_tab->g->perso->
        slide_effect.y / 2;
        if (fabs(rpg_tab->g->perso->slide_effect.y) < 0.1)
            rpg_tab->g->perso->slide_effect.y = 0;
        sfClock_restart(rpg_tab->g->perso->guy->anim_clock);
    }
}

void animate_explose(rpg_t *rpg_tab, int i, float seconds)
{
    rpg_tab->g->enemy[i]->blop->sprite_rect.top = 400;
    if (rpg_tab->g->enemy[i]->hp <= 0) return;
    if (seconds > 0.1) {
        rpg_tab->g->enemy[i]->blop->sprite_rect.left += rpg_tab->
        g->enemy[i]->blop->sprite_rect.width;
        if (rpg_tab->g->enemy[i]->blop->sprite_rect.left >=
        rpg_tab->g->enemy[i]->blop->sprite_rect.width * 6)
            rpg_tab->g->enemy[i]->hp = 0;
        if (rpg_tab->g->enemy[i]->hp <= 0 && sfFloatRect_intersects
        (&rpg_tab->g->perso->guy_hitbox, &rpg_tab->g->enemy[i]->explosion,
        NULL) == sfTrue) {
            rpg_tab->g->enemy[i]->blop->sprite_pos = (sfVector2f){-1000, -1000};
            rpg_tab->g->enemy[i]->blop_hitbox = (sfFloatRect){-1000, -1000,
            0, 0};
            rpg_tab->g->enemy[i]->blop->sprite_frect = (sfFloatRect){-1000,
            -1000, 0, 0};
            rpg_tab->g->enemy[i]->explosion = (sfFloatRect){-1000, -1000, 0, 0};
            rpg_tab->g->var->hp -= 10;
        } sfClock_restart(rpg_tab->g->enemy[i]->blop->anim_clock);
    }
}

void animate_mob_blop(rpg_t *rpg_tab, int i)
{
    sfTime time = sfClock_getElapsedTime(rpg_tab->g->enemy[i]->blop->
    anim_clock);
    float seconds = time.microseconds / 1000000.0;

    if (rpg_tab->g->enemy[i]->detected == true) {
        animate_explose(rpg_tab, i, seconds);
        return;
    }
    if (((rpg_tab->g->enemy[i]->mv_right == false
    && rpg_tab->g->enemy[i]->mv_left == false
    && rpg_tab->g->enemy[i]->mv_up == false
    && rpg_tab->g->enemy[i]->mv_down == false)
    || rpg_tab->g->enemy[i]->hit == 1)) {
        rpg_tab->g->enemy[i]->blop->sprite_rect.left = 0;
    } else {
        if (seconds > 0.04) {
            decal_rect_guy(&(rpg_tab->g->enemy[i]->blop->sprite_rect),
            rpg_tab->g->enemy[i]->blop->sprite_rect.width * rpg_tab->int_coeff,
            rpg_tab->g->enemy[i]->blop->sprite_rect.width * 12, 100);
            if (((rpg_tab->g->enemy[i]->mv_right == true
            && rpg_tab->g->enemy[i]->mv_left == true)
            || (rpg_tab->g->enemy[i]->mv_up == true
            && rpg_tab->g->enemy[i]->mv_down == true))
            && rpg_tab->g->enemy[i]->nb_pressed == 2) {
                rpg_tab->g->enemy[i]->blop->sprite_rect.left = 0;
            }
            sfClock_restart(rpg_tab->g->enemy[i]->blop->anim_clock);
        }
    }
}