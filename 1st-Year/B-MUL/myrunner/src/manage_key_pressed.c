/*
** EPITECH PROJECT, 2021
** manage_key_pressed.c
** File description:
** my_runner
*/

#include "my_runner.h"

void manage_key_pressed(sfEvent event, game_object ***sprite)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && (*sprite)[16]->jump == 0) {
        if ((*sprite)[16]->pos.y == 940) {
            (*sprite)[16]->offset = 243;
            (*sprite)[16]->jump = 1;
        }
    }
}