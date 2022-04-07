/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_quest_bidon(rpg_t *rpg_tab)
{
    for (int i = 0; i < 3; i++) {
        rpg_tab->g->bidon->bidon_layer[i] = get_my_sprite(rpg_tab, BIDON,
        (sfVector2f){0, 0}, (sfIntRect){291 * i, 0, 291, 401});
    }
    rpg_tab->g->bidon->bidon_layer[1]->sprite_rect =
    (sfIntRect){291, 401, 291, 0};
    rpg_tab->g->bidon->button = get_my_sprite(rpg_tab, BIDON,
    (sfVector2f){0, 0}, (sfIntRect){0, 401, 205, 137});
    rpg_tab->g->bidon->button->sprite_frect = (sfFloatRect){0, 401, 205, 137};
    rpg_tab->g->bidon->quest_reach = (sfFloatRect){0, 0, 20, 20};
    rpg_tab->g->bidon->seconds = 0;
    rpg_tab->g->bidon->button->anim_clock = sfClock_create();
}

void init_quest(rpg_t *rpg_tab)
{
    init_quest_bidon(rpg_tab);
}