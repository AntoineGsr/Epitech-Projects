/*
** EPITECH PROJECT, 2020
** restart_sprite.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void restart_sprite(S_base *bird, sfRenderWindow *window, int i, float seconds)
{
    if (bird[i].offset >= bird[i].max_value && bird[i].kill == 2
        && bird[i].pos.y >= 940) {
        if (bird[i].start_stop == 4) {
            bird[i].sprite_copy = sfSprite_copy(bird[i].sprite);
            bird[i].start_stop = 0;
            bird[i].rect.top = 0;
            bird[i].rect.left = 0;
            bird[i].rect.width = 95;
            bird[i].rect.height = 82;
            bird[i].offset = 0;
            bird[i].max_value = 475;
            bird[i].speed = (bird[i].speed + bird[i].score * 2) * seconds;
            bird[i].kill = 0;
            bird[i].dead_body = 0;
            bird[i].pos.x = -1 * rand() % 1000;
            bird[i].pos.y = rand() % 600;
        }
        bird[i].start_stop += 1;
    }
}
