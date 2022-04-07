/*
** EPITECH PROJECT, 2020
** display_my_window.c
** File description:
** my_runner
*/

#include "my_runner.h"

void display_my_window(sfRenderWindow *window, game_object **bck,
game_object **bck_copy)
{
    for (int i = 0; i < 7; i++) {
        parallax_effect(&bck[i], &bck_copy[i], i);
        sfSprite_setTexture(bck[i]->sprite, bck[i]->texture, sfTrue);
        sfSprite_setPosition(bck[i]->sprite, bck[i]->pos);
        sfRenderWindow_drawSprite(window, bck[i]->sprite, NULL);
        sfSprite_setTexture(bck_copy[i]->sprite, bck_copy[i]->texture, sfTrue);
        sfSprite_setPosition(bck_copy[i]->sprite, bck_copy[i]->pos);
        sfRenderWindow_drawSprite(window, bck_copy[i]->sprite, NULL);
    }
    sfRenderWindow_display(window);
}