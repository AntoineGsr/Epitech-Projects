/*
** EPITECH PROJECT, 2021
** gm_display_three.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void gm_twelve(rpg_t *rpg_tab)
{
    gd_one(rpg_tab);
    gd_two(rpg_tab);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->inventory->stats->
    hp_txt->text, NULL);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->inventory->stats->
    xp_txt->text, NULL);
    for (int i = 0; i < 9; i++) {
        if (rpg_tab->g->inventory->case_inv[i]->inventory != false) {
            sfSprite_setPosition(rpg_tab->g->inventory->case_inv[i]->inv_case->
            sprite, rpg_tab->g->inventory->case_inv[i]->inv_case->sprite_pos);
            sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->inventory->
            case_inv[i]->inv_case->sprite, NULL);
        }
    }
}

void gd_five(rpg_t *rpg_tab)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(rpg_tab->g->bidon->bidon_layer[i]->sprite,
        rpg_tab->g->bidon->bidon_layer[i]->sprite_pos);
        sfSprite_setTextureRect(rpg_tab->g->bidon->bidon_layer[i]->sprite,
        rpg_tab->g->bidon->bidon_layer[i]->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->bidon->
        bidon_layer[i]->sprite, NULL);
    }
    sfSprite_setPosition(rpg_tab->g->bidon->button->sprite, rpg_tab->g->
    bidon->button->sprite_pos);
    sfSprite_setTextureRect(rpg_tab->g->bidon->button->sprite, rpg_tab->g->
    bidon->button->sprite_rect);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->bidon->button->
    sprite, NULL);
}