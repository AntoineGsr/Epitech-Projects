/*
** EPITECH PROJECT, 2021
** create_musics_game.c
** File description:
** my_runner
*/

#include "my_runner.h"

void create_music(game_object ***sprite)
{
    (*sprite)[16]->my_music1 = sfMusic_createFromFile("./music/avatar.ogg");
    (*sprite)[16]->my_music2 = sfMusic_createFromFile("./music/demon.ogg");
    (*sprite)[16]->my_sound_effect = sfMusic_createFromFile
    ("./music/coin_sound.ogg");
    sfMusic_setLoop((*sprite)[16]->my_music1, sfTrue);
    sfMusic_setLoop((*sprite)[16]->my_music2, sfTrue);
    (*sprite)[16]->eight_d_sound = 0;
    (*sprite)[16]->sound_effect = 1;
    (*sprite)[16]->music = 1;
    (*sprite)[16]->music_started = 0;
}