/*
** EPITECH PROJECT, 2020
** create_object.c
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void init_object_numbers(game_object **obj)
{
    (*obj)->move = 0;
    (*obj)->speed_parallax = 0;
    (*obj)->restart_press = 0;
    (*obj)->mouse_left_click = 0;
    (*obj)->music = 37;
    (*obj)->sound_effect = 37;
    (*obj)->load_save = 0;
    (*obj)->type_plante = 0;
    (*obj)->build_lvl = 0;
    (*obj)->size_rect = 0;
    (*obj)->animation_time = 0;
    (*obj)->can_up_lvl = 0;
    (*obj)->cost_lvl_up = 300;
    (*obj)->have_to_shoot = 0;
    (*obj)->sun_wallet = 150;
    (*obj)->price = 0;
    (*obj)->can_action = 0;
    (*obj)->range = 0;
    (*obj)->music_started = 0;
}

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
    obj->offset = 0;
    obj->count = 0;
    obj->speed_x = 325;
    obj->speed_y = 475;
    obj->life = 1;
    obj->case_map = 0;
    init_object_numbers(&obj);
    obj->clock = sfClock_create();
    return (obj);
}