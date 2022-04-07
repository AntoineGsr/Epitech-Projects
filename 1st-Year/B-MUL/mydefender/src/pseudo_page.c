/*
** EPITECH PROJECT, 2021
** pseudo_page.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void pseudo_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    (*sprite)[5] = create_object("./images/pseudo.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 512, 768});
    display_sprite(*sprite, window, 5, 6);
    input_name_init(&(*sprite)[0], (sfColor){0, 0, 0, 175}, window,
    (sfVector2f){220 - my_strlen((*sprite)[0]->pseudostring) * 5, 380});
}