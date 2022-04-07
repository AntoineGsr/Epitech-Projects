/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void animate_generic(sfIntRect *rect, int dec, int max, int base_mv)
{
    int repeat = dec / base_mv;
    for (int i = 0; i < repeat; i++) {
        (*rect).left += base_mv;
        if ((*rect).left >= max) {
            (*rect).left = 0;
        }
    }
}