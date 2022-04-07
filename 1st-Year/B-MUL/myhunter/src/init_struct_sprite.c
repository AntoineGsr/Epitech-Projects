/*
** EPITECH PROJECT, 2020
** init_struct_sprite.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void init_coord_sprite(S_base *bird, int i)
{
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
    bird[i].score  = 0;
}

void init_struct_sprite(S_base *bird, char const *filepath, int nb_bird)
{
    srand(time(NULL));
    for (int i = 0; i < nb_bird; i++) {
        bird[i].texture = sfTexture_createFromFile(filepath, NULL);
        bird[i].sprite = sfSprite_create();
        bird[i].sprite_copy = sfSprite_copy(bird[i].sprite);
        init_coord_sprite(bird, i);
        bird[i].nb_bird = nb_bird;
    }
    bird[0].life = 0;
    bird[0].exit_button = 0;
}
