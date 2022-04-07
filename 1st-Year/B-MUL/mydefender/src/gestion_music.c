/*
** EPITECH PROJECT, 2021
** music_gestion.c
** File description:
** my_runner
*/

#include "../include/my_defender.h"

void create_music(const char *fl_path, game_object **sprite)
{
    (*sprite)->musics = sfMusic_createFromFile(fl_path);
    sfMusic_setLoop((*sprite)->musics, sfTrue);
}

void create_sound(const char *fl_path, game_object **mob)
{
    (*mob)->soundbuffer = sfSoundBuffer_createFromFile(fl_path);
    (*mob)->sound = sfSound_create();
    sfSound_setBuffer((*mob)->sound, (*mob)->soundbuffer);
}

void use_sound_effect(game_object **mob)
{
    sfSound_setVolume((*mob)->sound, ((*mob)->sound_effect / 74) * 120);
    sfSound_play((*mob)->sound);
}

void gestion_music(game_object **sprite, enum pages *state)
{
    if (*state > PSEUDO) {
        if ((*sprite)->music_started == 0) {
            sfMusic_play((*sprite)->musics);
            (*sprite)->music_started += 1;
        }
        sfMusic_setVolume((*sprite)->musics, (*sprite)->music);
    }
}