/*
** EPITECH PROJECT, 2020
** back_base.h
** File description:
** my_defender
*/

#include "my_defender.h"

#ifndef GAME_H_
#define GAME_H_

typedef struct game_object game_object;
struct game_object {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    sfText *pseudotext;
    sfFont *fontpseudo;
    char *pseudostring;
    int offset;
    int offset_origin;
    int offset_shoot;
    int count;
    float speed_x;
    float speed_y;
    float speed_parallax;
    int life;
    int case_map;
    float move;
    sfMusic *musics;
    sfSoundBuffer *soundbuffer;
    sfSound *sound;
    float sound_effect;
    float music;
    int eight_d_sound;
    int music_started;
    int restart_press;
    int mouse_left_click;
    int load_save;
    int type_plante;
    int build_lvl;
    int size_rect;
    float animation_time;
    int can_up_lvl;
    int cost_lvl_up;
    int have_to_shoot;
    int damage;
    int sun_wallet;
    int price;
    int range;
    sfVector2f mouse_pos;
    float can_action;
    sfClock *clock_action;
};

typedef struct l_list l_list;
struct l_list
{
    int pos_x_map;
    int pos_y_map;
    game_object *mob;
    game_object *lvl_up;
    l_list *previous;
    l_list *next;
};

typedef struct list list;
struct list
{
    int nb_sun;
    int score;
    int load_save;
    int nb_entity;
    int max_node;
    int **map;
    int pos_x_map;
    int pos_y_map;
    int first_creation;
    int life_house;
    sfVector2f new_node_pos;
    l_list *first;
    l_list *last;
};

#endif /* GAME_H_ */
