/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

float get_decal_min_map(rpg_t *rpg_tab)
{
    float to_return = 0;

    to_return = rpg_tab->g->perso->guy_center.x;
    return (to_return);
}

void display_min_map(rpg_t *rpg_tab)
{
    sfRenderWindow_setView(rpg_tab->window, rpg_tab->min_map_view);
    sfView_setCenter(rpg_tab->min_map_view, (sfVector2f)
    {get_decal_min_map(rpg_tab), sfView_getSize(rpg_tab->min_map_view).y / 2});
    display_tiles(rpg_tab);
    sfSprite_setPosition(rpg_tab->g->red_arrow->sprite,
    rpg_tab->g->perso->guy_center);
    sfRenderWindow_drawSprite(rpg_tab->window,
    rpg_tab->g->red_arrow->sprite, NULL);
    sfRenderWindow_setView(rpg_tab->window, rpg_tab->view);
}