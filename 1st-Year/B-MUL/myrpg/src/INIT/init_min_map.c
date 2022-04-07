/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_min_map(rpg_t *rpg_tab)
{
    rpg_tab->g->red_arrow = get_my_sprite(rpg_tab,
    "assets/png/game/red_arrow.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 175, 276});
    sfSprite_setOrigin(rpg_tab->g->red_arrow->sprite,
    (sfVector2f) {87.5, 276});
    rpg_tab->min_map_view = sfView_create();
    sfView_setSize(rpg_tab->min_map_view,
    (sfVector2f) {1920 * 2.5,
    1080 * 2.5});
    sfView_setCenter(rpg_tab->min_map_view,
    (sfVector2f) {sfView_getSize(rpg_tab->min_map_view).x / 2,
    sfView_getSize(rpg_tab->min_map_view).y / 2});
    sfView_setViewport(rpg_tab->min_map_view,
    (sfFloatRect) {0.80, 0, 0.20, 0.20});
}