/*
** EPITECH PROJECT, 2021
** type_plante_create.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void plante_one(list **gbl, game_object **mob)
{
    (*gbl)->nb_sun -= 50;
    (*gbl)->new_node_pos = (sfVector2f){(*gbl)->new_node_pos.x - 58,
    (*gbl)->new_node_pos.y - 128};
    *mob = create_object("./images/tournesol.png",
    (*gbl)->new_node_pos, (sfIntRect){0, 0, 116, 128});
    (*mob)->offset = 928;
    (*mob)->offset_origin = 928;
    (*mob)->animation_time = 0.075;
    (*mob)->can_action = 5;
}

void plante_two(list **gbl, game_object **mob)
{
    (*gbl)->nb_sun -= 100;
    (*gbl)->new_node_pos = (sfVector2f){(*gbl)->new_node_pos.x - 58,
    (*gbl)->new_node_pos.y - 128};
    *mob = create_object("./images/shooter.png",
    (*gbl)->new_node_pos, (sfIntRect){0, 0, 116, 128});
    (*mob)->offset = 928;
    (*mob)->offset_origin = 928;
    (*mob)->offset_shoot = 348;
    (*mob)->animation_time = 0.07;
    (*mob)->can_action = 3;
    (*mob)->range = 650;
    create_sound("./sounds/effects/shoot_sound.ogg", mob);
}

void plante_three(list **gbl, game_object **mob)
{
    (*gbl)->nb_sun -= 150;
    (*gbl)->new_node_pos = (sfVector2f){(*gbl)->new_node_pos.x - 90,
    (*gbl)->new_node_pos.y - 155};
    *mob = create_object("./images/carnivor.png",
    (*gbl)->new_node_pos, (sfIntRect){0, 0, 180, 155});
    (*mob)->offset = 1620;
    (*mob)->offset_origin = 1620;
    (*mob)->offset_shoot = 1440;
    (*mob)->animation_time = 0.075;
    (*mob)->can_action = 6;
    (*mob)->range = 100;
    create_sound("./sounds/effects/carnivor_sound.ogg", mob);
}

void plante_foor(list **gbl, game_object **mob)
{
    (*gbl)->nb_sun -= 25;
    (*gbl)->new_node_pos = (sfVector2f){(*gbl)->new_node_pos.x - 41,
    (*gbl)->new_node_pos.y - 80};
    *mob = create_object("./images/bomb.png",
    (*gbl)->new_node_pos, (sfIntRect){0, 0, 83, 80});
    (*mob)->offset = 664;
    (*mob)->offset_origin = 664;
    (*mob)->offset_shoot = 294;
    (*mob)->animation_time = 3;
    (*mob)->can_action = 0.7;
    (*mob)->range = 5;
    create_sound("./sounds/effects/mine_sound.ogg", mob);
}

void plante_five(list **gbl, game_object **mob)
{
    (*gbl)->nb_sun -= 175;
    (*gbl)->new_node_pos = (sfVector2f){(*gbl)->new_node_pos.x - 65,
    (*gbl)->new_node_pos.y - 124};
    *mob = create_object("./images/frozen.png",
    (*gbl)->new_node_pos, (sfIntRect){0, 0, 131, 124});
    (*mob)->offset = 1048;
    (*mob)->offset_origin = 1048;
    (*mob)->offset_shoot = 393;
    (*mob)->animation_time = 0.07;
    (*mob)->can_action = 2.5;
    (*mob)->range = 750;
    create_sound("./sounds/effects/shoot_sound.ogg", mob);
}