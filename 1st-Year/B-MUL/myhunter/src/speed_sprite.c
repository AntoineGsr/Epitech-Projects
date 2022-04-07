/*
** EPITECH PROJECT, 2020
** speed_sprite.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void speed_sprite(S_base *bird, int i, float seconds)
{
    bird[i].pos.x +=  (bird[i].speed + bird[i].score * 2) * seconds;
    sfSprite_setPosition(bird[i].sprite, bird[i].pos);
}