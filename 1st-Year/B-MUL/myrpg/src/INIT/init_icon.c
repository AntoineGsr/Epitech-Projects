/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_icon_extra(rpg_t *rpg_tab)
{
    rpg_tab->icons->icon[5] =
    sfImage_createFromFile("assets/png/extra/pack/frame_6.png");
    rpg_tab->icons->icon[6] =
    sfImage_createFromFile("assets/png/extra/pack/frame_7.png");
    rpg_tab->icons->icon[7] =
    sfImage_createFromFile("assets/png/extra/pack/frame_8.png");
    rpg_tab->icons->icon[8] =
    sfImage_createFromFile("assets/png/extra/pack/frame_9.png");
    rpg_tab->icons->icon[9] =
    sfImage_createFromFile("assets/png/extra/pack/frame_10.png");
    rpg_tab->icons->icon[10] =
    sfImage_createFromFile("assets/png/extra/pack/frame_11.png");
    sfRenderWindow_setIcon(rpg_tab->window, 216, 216,
    sfImage_getPixelsPtr(rpg_tab->icons->icon[0]));
}

void init_icon(rpg_t *rpg_tab)
{
    rpg_tab->icons->index = 0;
    rpg_tab->icons->icon_clock = sfClock_create();
    rpg_tab->icons->icon = malloc(sizeof(sfImage *) * 11);
    rpg_tab->icons->icon[0] =
    sfImage_createFromFile("assets/png/extra/pack/frame_1.png");
    rpg_tab->icons->icon[1] =
    sfImage_createFromFile("assets/png/extra/pack/frame_2.png");
    rpg_tab->icons->icon[2] =
    sfImage_createFromFile("assets/png/extra/pack/frame_3.png");
    rpg_tab->icons->icon[3] =
    sfImage_createFromFile("assets/png/extra/pack/frame_4.png");
    rpg_tab->icons->icon[4] =
    sfImage_createFromFile("assets/png/extra/pack/frame_5.png");
    init_icon_extra(rpg_tab);
}