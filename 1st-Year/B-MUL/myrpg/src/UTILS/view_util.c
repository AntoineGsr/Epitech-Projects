/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

sfVector2f sfview_my_getpos(rpg_t *rpg_tab, sfView *view)
{
    sfVector2f pos;

    pos = ((sfVector2f) {sfView_getCenter(view).x - (sfView_getSize(view
    ).x / 2), sfView_getCenter(view).y - (sfView_getSize(view).y) / 2});
    return (pos);
}