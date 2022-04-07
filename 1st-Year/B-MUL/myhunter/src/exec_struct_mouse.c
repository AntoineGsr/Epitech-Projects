/*
** EPITECH PROJECT, 2020
** exec_struct_mouse.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void exec_struct_mouse(S_base *mouse, sfRenderWindow *window,
sfMouseMoveEvent event)
{
    mouse->pos.x = event.x;
    mouse->pos.y = event.y;
    sfSprite_setTexture(mouse->sprite, mouse->texture, sfTrue);
    sfSprite_setTextureRect(mouse->sprite, mouse->rect);
    sfSprite_setPosition(mouse->sprite, mouse->pos);
    sfRenderWindow_drawSprite(window, mouse->sprite, NULL);
}
