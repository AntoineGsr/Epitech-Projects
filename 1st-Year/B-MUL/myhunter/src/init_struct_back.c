/*
** EPITECH PROJECT, 2020
** init_struct_back.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void init_struct_back(B_base *bck, char const *filepath)
{
    bck->texture = sfTexture_createFromFile(filepath, NULL);
    bck->sprite = sfSprite_create();
    exec_struct_back(*&bck);
}
