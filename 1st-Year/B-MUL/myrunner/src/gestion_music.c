/*
** EPITECH PROJECT, 2021
** music_gestion.c
** File description:
** my_runner
*/

#include "my_runner.h"

void update_coin_sound(list **gbl, l_list **obstacles, game_object ***sprite)
{
    sfMusic_setPlayingOffset((*sprite)[16]->my_sound_effect, (sfTime){0});
    sfMusic_play((*sprite)[16]->my_sound_effect);
}

void gestion_music(game_object **sprite, enum pages *state)
{
    if (*state == GAME && sprite[16]->music_started == 0) {
        if (sprite[16]->eight_d_sound == 0) {
            sfMusic_play(sprite[16]->my_music1);
            sfMusic_pause(sprite[16]->my_music2);
        } else {
            sfMusic_play(sprite[16]->my_music2);
            sfMusic_pause(sprite[16]->my_music1);
        }
        sprite[16]->music_started = 1;
    }
    sfMusic_setVolume(sprite[16]->my_music1, sprite[16]->music * 80);
    sfMusic_setVolume(sprite[16]->my_music2, sprite[16]->music * 80);
    sfMusic_setVolume(sprite[16]->my_sound_effect,
    sprite[16]->sound_effect * 10);
    if (*state > PAUSE) {
        sfMusic_setVolume(sprite[16]->my_music1, 0);
        sfMusic_setVolume(sprite[16]->my_music2, 0);
        sfMusic_setVolume(sprite[16]->my_sound_effect, 0);
    }
}