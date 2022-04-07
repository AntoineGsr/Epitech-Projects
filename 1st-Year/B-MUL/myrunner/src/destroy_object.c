/*
** EPITECH PROJECT, 2020
** destroy_object.c
** File description:
** my_runner
*/

#include "my_runner.h"

void destroy_object(game_object *obj)
{
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    sfClock_destroy(obj->clock);
    free(obj);
}