/*
** EPITECH PROJECT, 2020
** my_hunter.h
** File description:
** my_hunter
*/

#ifndef MYHUNTER_H_
#define MYHUNTER_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>
#include <SFML/Config.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <time.h>
#include "back_base.h"
#include "sprite_base.h"
#include "music_base.h"
#include "../lib/my/my.h"

typedef struct s_framebuffer
{
    unsigned char *pixels;
    unsigned int width;
    unsigned int height;
} t_framebuffer;

int exe_game(S_base *bird, B_base *bck, sfRenderWindow *window, sfEvent event);

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height);

int display_menu(sfRenderWindow *window, B_base *bck, sfEvent event,
S_base *menu);

void display_my_window(sfRenderWindow *window, B_base *bck, S_base *bird,
sfTime time);

void init_struct_mouse(S_base *mouse, char const *filepath,
sfRenderWindow *window, sfMouseMoveEvent event);

void analyse_events(B_base *bck, S_base *bird, sfRenderWindow *window,
sfEvent event);

void close_window(sfRenderWindow *window, sfEvent event);

void exec_struct_mouse(S_base *mouse, sfRenderWindow *window,
sfMouseMoveEvent event);

void exec_struct_back(B_base *bck);

void exec_struct_bird(S_base *bird, int nb_birds);

void exec_music(M_base *song, float time, float vol, int play);

void init_struct_back(B_base *bck, char const *filepath);

void init_struct_sprite(S_base *bird, char const *filepath, int nb_bird);

void init_struct_music(M_base *song, char const *filepath);

void manage_mouse_click(sfEvent event, S_base *bird);

void move_rect(S_base *bird, int i);

void moving_sprite_bird(B_base *bck, S_base *bird, sfRenderWindow *window,
sfTime time);

void restart_sprite(S_base *bird, sfRenderWindow *window, int i,
float seconds);

void speed_sprite(S_base *bird, int i, float seconds);

int restart_game(sfRenderWindow *window, sfEvent event,
S_base *menu, S_base *bird);

#endif /* MYHUNTER_H_ */
