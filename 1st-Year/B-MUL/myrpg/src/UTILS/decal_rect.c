/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void decal_rect_generic(sfIntRect *rect, sfVector2f dec, sfVector2f max)
{
    int lat_repeat = -1;
    float tmp_dec = dec.x;

    for (lat_repeat = -1; max.x / tmp_dec >= 1.0;) {
        tmp_dec = tmp_dec + max.x;
        lat_repeat++;
    }
    for (int i = 0; i < lat_repeat; i++) {
        (*rect).top += dec.y;
        if ((*rect).top >= max.y)
            (*rect).top = 0;
    } if ((*rect).left + dec.x >= max.x) {
        (*rect).top += dec.y;
        if ((*rect).top >= max.y)
            (*rect).top = 0;
        (*rect).left = dec.x - (max.x - (*rect).left);
    } else (*rect).left += dec.x;
}