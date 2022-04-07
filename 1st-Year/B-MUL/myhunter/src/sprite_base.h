/*
** EPITECH PROJECT, 2020
** graphical_base.h
** File description:
** struct
*/

#include "my_hunter.h"

#ifndef SPR_H_
#define SPR_H_

typedef struct S_base S_base;
struct S_base {
    sfTexture *texture;
    sfSprite *sprite;
    sfSprite *sprite_copy;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2i m_pos;
    sfMouseMoveEvent mouseMove;
    sfClock *clock;
    sfTime time;
    int life;
    int offset;
    int max_value;
    int kill;
    int play;
    int start_stop;
    int dead_body;
    float speed;
    int score;
    int nb_bird;
    int exit_button;
};

#endif /* SPR_H_ */