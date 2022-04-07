/*
** EPITECH PROJECT, 2020
** move_rect.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void dead_gestion_next(S_base *bird, int i)
{
    if (bird[i].offset >= bird[i].max_value) {
        bird[i].rect.left = 190;
    } else
        bird[i].rect.left = bird[i].offset;
}

void dead_gestion(S_base *bird, int i)
{
    if (bird[i].kill == 1) {
        bird[i].score += 1;
        bird[i].kill += 1;
        bird[i].offset = 0;
        bird[i].max_value = 285;
        bird[i].rect.top = 95;
        bird[i].rect.left = bird[i].offset;
    } else if (bird[i].pos.y < 940) {
        bird[i].offset += 95;
        bird[i].pos.y += 33;
        bird[i].speed = 25;
        dead_gestion_next(*&bird, i);
    } else {
        bird[i].speed = 0;
        bird[i].rect.left = 285;
    }
}

void on_the_floor(S_base *bird, int i)
{
    bird[0].life += 1;
    bird[i].rect.top = 0;
    bird[i].rect.left = 0;
    bird[i].rect.width = 95;
    bird[i].rect.height = 82;
    bird[i].offset = 0;
    bird[i].max_value = 475;
    bird[i].speed = rand() % (200 - 100) + 500;
    bird[i].kill = 0;
    bird[i].start_stop = 0;
    bird[i].dead_body = 0;
    bird[i].pos.x = -1 * rand() % 1000;
    bird[i].pos.y = rand() % 600;
}

void move_rect(S_base *bird, int i)
{
    sfClock *clock;
    sfTime time;
    float seconds = 0;

    if (bird[i].offset < bird[i].max_value || bird[i].kill == 2) {
        if (bird[i].kill == 0) {
            bird[i].rect.top = 0;
            bird[i].rect.left = bird[i].offset;
            bird[i].offset += 95;
            bird[i].speed = rand() % (200 - 100) + 500;
        } else
            dead_gestion(*&bird, i);
    } else {
        bird[i].offset = 95;
        bird[i].rect.left = 0;
    }
    if (bird[i].pos.x > 1920)
        on_the_floor(bird, i);
}
