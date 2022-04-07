/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void handle_cursor(rpg_t *rpg_tab)
{
    rpg_tab->u->c_pos_previous = rpg_tab->u->c_pos;
    rpg_tab->u->c_box_previous = rpg_tab->u->c_box;
    rpg_tab->u->c_pos = sfRenderWindow_mapPixelToCoords(rpg_tab->window
    , sfMouse_getPositionRenderWindow(rpg_tab->window), NULL);
    rpg_tab->u->c_box = (sfFloatRect)
    {rpg_tab->u->c_pos.x, rpg_tab->u->c_pos.y, 1, 1};
    sfSprite_setPosition(rpg_tab->u->cursor->sprite, rpg_tab->u->c_pos);
    if (sfClock_getElapsedTime(rpg_tab->u->cursor->anim_clock).microseconds
    / 1000000.0 > 0.1) {
        sfClock_restart(rpg_tab->u->cursor->anim_clock);
        decal_rect_generic(&(rpg_tab->u->cursor->sprite_rect), (sfVector2f)
        {200 * rpg_tab->int_coeff, 200},
        (sfVector2f){1000, 400});
        sfSprite_setTextureRect(rpg_tab->u->cursor->sprite,
        rpg_tab->u->cursor->sprite_rect);
    }
    sfRenderWindow_drawSprite(rpg_tab->window,
    rpg_tab->u->cursor->sprite, NULL);
}