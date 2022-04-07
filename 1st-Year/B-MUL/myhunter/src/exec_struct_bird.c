/*
** EPITECH PROJECT, 2020
** exec_struct_bird.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void exec_struct_bird(S_base *bird, int nb_birds)
{
    for (int i = 0; i < nb_birds; i++) {
        sfSprite_setTexture(bird[i].sprite, bird[i].texture, sfTrue);
        sfSprite_setTextureRect(bird[i].sprite, bird[i].rect);
    }
}
