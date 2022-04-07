/*
** EPITECH PROJECT, 2020
** exec_music.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void exec_music(M_base *song, float time, float vol, int play)
{
    sfMusic_setVolume(song->music, vol);
    sfMusic_play(song->music);
}