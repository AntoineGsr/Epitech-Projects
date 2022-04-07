/*
** EPITECH PROJECT, 2020
** parallax_effect.h
** File description:
** my_runner
*/

#include "my_runner.h"

void parallax_effect(game_object **bck, game_object **bck_copy, int i)
{
    float seconds = 0;

    (*bck)->time = sfClock_restart((*bck)->clock);
    seconds = (*bck)->time.microseconds / 1000000.0;
    (*bck)->pos.x += (-6) * (i * i) * seconds;
    (*bck)->speed_parallax = (-6) * (i * i) * seconds;
    (*bck_copy)->time = sfClock_restart((*bck_copy)->clock);
    if ((*bck)->pos.x < -1920)
        (*bck)->pos.x = 0;
    (*bck_copy)->pos.x = (*bck)->pos.x + 1920;
}