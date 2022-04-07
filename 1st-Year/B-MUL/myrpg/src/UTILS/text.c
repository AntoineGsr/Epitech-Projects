/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../../include/my.h"

void animate_text(rpg_t *rpg_tab, text_t *text, int refresh_rate, int *col)
{
    float color_one = sin(text->x_dec / refresh_rate) * col[0] + col[0];
    float color_two = sin(text->x_dec / refresh_rate) * col[1] + col[1];

    text->x_dec = text->x_dec + 1 * rpg_tab->coeff;
    sfText_setColor(text->text, (sfColor) {color_one, color_two, col[2], 255});
}