/*
** EPITECH PROJECT, 2020
** init_struct_mouse.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void init_struct_mouse(S_base *mouse, char const *filepath,
sfRenderWindow *window, sfMouseMoveEvent event)
{
    srand(time(NULL));
    mouse->texture = sfTexture_createFromFile(filepath, NULL);
    mouse->sprite = sfSprite_create();
    mouse->rect.top = 0;
    mouse->rect.left = 0;
    mouse->rect.width = 23;
    mouse->rect.height = 23;
    mouse->pos.x = event.x;
    mouse->pos.y = event.y;
}
