/*
** EPITECH PROJECT, 2021
** charact_animation.c
** File description:
** my_runner
*/

#include "my_runner.h"

void put_on_the_floar(game_object *charact, float seconds)
{
    if (charact->pos.y >= 940) {
        charact->jump = 0;
        charact->offset = 324;
        charact->pos.y = 940;
        charact->rect.top = 0;
        charact->speed_y = 265;
    }
}

void run_animation_character(game_object *charact, float seconds)
{
    if (charact->rect.left < charact->offset && charact->offset == 324) {
        charact->speed_y = 265;
        charact->rect.left += 81;
        charact->rect.top = 0;
    } else if (charact->offset == 324) {
        charact->rect.left = 0;
        charact->speed_y = 265;
    }
}

void up_jump_animation_character(game_object *charact, float seconds)
{
    if (charact->rect.left < charact->offset && charact->offset == 243) {
        if (charact->rect.top == 0) {
            charact->rect.left = 0;
            charact->rect.top = 81;
        } else if (seconds > 0.07)
            charact->rect.left += 81;
        charact->pos.y -= seconds * charact->speed_y;
    } else if (charact->offset == 243) {
        charact->rect.left = 81;
        charact->pos.y -= seconds * charact->speed_y;
    }
}

void down_jump_animation_character(game_object *charact, float seconds)
{
    if (charact->rect.left < charact->offset && charact->offset == 243) {
        if (charact->pos.y <= 840) {
            charact->speed_y -= 500 * seconds;
        }
    }
}

void animate_character(game_object **sprite)
{
    sfTime time = sfClock_getElapsedTime(sprite[16]->clock);
    float seconds = time.microseconds / 1000000.0;

    up_jump_animation_character(sprite[16], seconds);
    down_jump_animation_character(sprite[16], seconds);
    put_on_the_floar(sprite[16], seconds);
    if (seconds > 0.07) {
        run_animation_character(sprite[16], seconds);
        sfClock_restart(sprite[16]->clock);
    }
}