/*
** EPITECH PROJECT, 2020
** back_base.h
** File description:
** my_runner
*/

#include "my_runner.h"

#ifndef GAME_H_
#define GAME_H_

typedef struct l_list l_list;
struct l_list
{
    int obs;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    l_list *previous;
    l_list *next;
};

typedef struct list list;
struct list
{
    int ac;
    char *av;
    int nb_obs;
    int first_pos;
    float speed;
    l_list *first;
    l_list *last;
};

typedef struct game_object game_object;
struct game_object {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    int offset;
    int jump;
    float speed_y;
    float speed_parallax;
    int life;
    int case_map;
    float move;
    sfMusic *my_music1;
    sfMusic *my_music2;
    sfMusic *my_sound_effect;
    int sound_effect;
    int music;
    int eight_d_sound;
    int music_started;
    int restart_press;
};

#endif /* GAME_H_ */
