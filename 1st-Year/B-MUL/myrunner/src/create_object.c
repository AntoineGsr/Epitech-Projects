/*
** EPITECH PROJECT, 2020
** create_object.c
** File description:
** my_runner
*/

#include "my_runner.h"

game_object *create_object(const char *fl_path, sfVector2f pos, sfIntRect rect)
{
    game_object *obj = malloc(sizeof(game_object));

    if (obj == NULL)
        return NULL;
    obj->texture = sfTexture_createFromFile(fl_path, NULL);
    obj->sprite = sfSprite_create();
    obj->pos.x = pos.x;
    obj->pos.y = pos.y;
    obj->rect = rect;
    obj->offset = 324;
    obj->jump = 0;
    obj->speed_y = 0;
    obj->life = 1;
    obj->case_map = 0;
    obj->move = 0;
    obj->speed_parallax = 0;
    obj->restart_press = 0;
    obj->clock = sfClock_create();
    return (obj);
}