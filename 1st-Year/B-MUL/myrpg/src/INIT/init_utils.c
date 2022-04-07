/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_utils_two(rpg_t *rpg_tab)
{
    rpg_tab->u->c_box = (sfFloatRect)
    {rpg_tab->u->c_pos.x, rpg_tab->u->c_pos.y, 1, 1};
    rpg_tab->keys->right = 0;
    rpg_tab->keys->left = 0;
    rpg_tab->keys->up = 0;
    rpg_tab->keys->mv_down = 0;
    rpg_tab->u->c_pos_previous =
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    sfMouse_getPositionRenderWindow(rpg_tab->window), NULL);
    rpg_tab->u->c_box_previous = (sfFloatRect)
    {rpg_tab->u->c_pos_previous.x, rpg_tab->u->c_pos_previous.y, 1, 1};
    sfRenderWindow_setMouseCursorVisible(rpg_tab->window, sfFalse);
    rpg_tab->u->cursor = get_my_sprite(rpg_tab,
    "assets/png/extra/cursor.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 200, 200});
    sfSprite_setScale(rpg_tab->u->cursor->sprite, (sfVector2f) {0.3, 0.3});
}

void init_utils(rpg_t *rpg_tab)
{
    rpg_tab->u->transi_x = 0;
    rpg_tab->u->clock_coeff = sfClock_create();
    rpg_tab->u->link_start = get_new_sound("assets/music/link_start.ogg", 70);
    rpg_tab->u->click_sound = get_new_sound("assets/music/click.ogg", 50);
    rpg_tab->u->transi_state = TRANSI_NO;
    rpg_tab->u->transi_black = get_my_sprite(rpg_tab,
    "assets/png/util/black.jpg",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    rpg_tab->u->c_pos = sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    sfMouse_getPositionRenderWindow(rpg_tab->window), NULL);
    init_utils_two(rpg_tab);
}