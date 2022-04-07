/*
** EPITECH PROJECT, 2020
** moving_sprite_bird.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void moving_sprite_bird(B_base *bck, S_base *bird,
sfRenderWindow *window, sfTime time)
{
    float seconds;
    int count = 0;
    float test = 0;

    seconds = time.microseconds / 1000000.0;
    for (int i = 0; i < bird[i].nb_bird; i++) {
        move_rect(bird, i);
        speed_sprite(bird, i, seconds);
    }
    count++;
}