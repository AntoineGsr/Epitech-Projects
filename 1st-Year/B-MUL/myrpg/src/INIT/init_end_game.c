/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_end_game(rpg_t *rpg_tab)
{
    rpg_tab->eg->end_anim = get_my_sprite(rpg_tab,
    "assets/png/end_game/end_game.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 728, 408});
    sfSprite_setScale(rpg_tab->eg->end_anim->sprite, (sfVector2f)
    {2.637362, 2.647058});
}