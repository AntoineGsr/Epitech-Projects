/*
** EPITECH PROJECT, 2020
** init_struct_music.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void init_struct_music(M_base *song, char const *filepath)
{
    song->music = sfMusic_createFromFile(filepath);
}
