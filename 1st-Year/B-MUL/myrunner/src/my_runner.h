/*
** EPITECH PROJECT, 2020
** my_runner.h
** File description:
** my_runner
*/

#ifndef MYRUNNER_H_
#define MYRUNNER_H_

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
#include "game_object.h"
#include "../lib/my/my.h"

typedef struct s_framebuffer
{
    unsigned char *pixels;
    unsigned int width;
    unsigned int height;
} t_framebuffer;

enum pages {
    PRESS,
    MENU,
    START,
    CONTROLS,
    SETTINGS,
    QUIT,
    CTRL,
    CTRL_BCK,
    STGS,
    STGS_BCK,
    STGS_8D,
    STGS_SOUND,
    STGS_MUSIC,
    GAME,
    HOME,
    PAUSE,
    PAUSE_CLICK,
    RESUME,
    RESTART,
    SOUND_EFFECT,
    MUSIC,
    EXIT,
    GAMEWIN,
    W_END_MENU,
    W_END_NEW_GAME,
    W_END_QUIT,
    GAMEOVER,
    L_END_MENU,
    L_END_NEW_GAME,
    L_END_QUIT
};

void reaction_obstacles(list **gbl, l_list **obstacles, enum pages *state,
game_object ***sprite);

void create_objects_obstacles(game_object ***sprite, int ac, char **av);

void destroy_under_map(list **gbl, l_list **obstacles);

int error_gestion(int ac, char **av);

int helper_gestion(int ac, char **av);

sfRenderWindow *create_my_window(unsigned int width, unsigned int height);

list *create_obstacles(int ac, char **av, l_list **obstacles);

list *create_all_objects(game_object ***sprite, int ac, char **av,
l_list **obstacles);

char *my_memset_char(int size);

void destroy_all_objects(game_object ***sprite, sfRenderWindow **window,
list **gbl, l_list **obstacles);

void create_objects_game(game_object ***sprite);

game_object *create_object(const char *fl_path, sfVector2f pos,
sfIntRect rect);

void create_music(game_object ***sprite);

char *filepath_bck(int i);

char *open_game_map(int ac, char **av);

void analyse_events(sfRenderWindow *window, sfEvent event,
game_object ***sprite, enum pages *state);

void gestion_page(game_object **sprite, enum pages *state,
sfRenderWindow *window, list **gbl);

void press_page(game_object **sprite, sfRenderWindow *window);

void game_page(game_object **sprite, enum pages *state,
sfRenderWindow *window, list **gbl);

void display_my_window(sfRenderWindow *window, game_object **bck,
game_object **bck_copy);

void parallax_effect(game_object **bck, game_object **bck_copy, int i);

void obstacles_gestion(list **gbl, l_list **obstacles, enum pages *state,
sfRenderWindow *window);

void destroy_objects_game(game_object ***sprite, sfRenderWindow *window);

void destroy_object(game_object *obj);

void destroy_obstacles(list **gbl, l_list **obstacles);

void destroy_coin(list **gbl, l_list **obstacles, l_list *stock);

void menu_page(game_object **sprite, enum pages state, sfRenderWindow *window);

void manage_mouse_click(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite);

void manage_key_pressed(sfEvent event, game_object ***sprite);

void manage_mouse_move(sfEvent event, enum pages *state);

void home_pause_page(game_object **sprite, enum pages state,
sfRenderWindow *window);

void animate_character(game_object **sprite);

void restart_clocks(game_object **sprite);

void gameover_page(game_object **sprite, enum pages *state,
sfRenderWindow *window);

void gameend_page(game_object **sprite, enum pages *state,
sfRenderWindow *window);

void gestion_music(game_object **sprite, enum pages *state);

void update_coin_sound(list **gbl, l_list **obstacles, game_object ***sprite);

void mouse_move_menu(sfEvent event, enum pages *state);

void mouse_move_controls(sfEvent event, enum pages *state);

void mouse_move_settings(sfEvent event, enum pages *state);

void mouse_move_game(sfEvent event, enum pages *state);

void mouse_move_pause(sfEvent event, enum pages *state);

void mouse_move_win(sfEvent event, enum pages *state);

void mouse_move_over(sfEvent event, enum pages *state);

void mouse_click_menu(enum pages *state, game_object ***sprite,
sfRenderWindow *window);

void mouse_click_pause(enum pages *state, game_object ***sprite,
sfRenderWindow *window);

void mouse_click_end(enum pages *state, game_object ***sprite,
sfRenderWindow *window);

void mouse_click_home(enum pages *state, game_object ***sprite,
sfRenderWindow *window);

void update_score(sfFont **font, sfText **text, sfVector2f pos_txt,
char *str);

void update_high_score(sfFont **font_hs, sfText **text_hs,
sfVector2f pos_txt_hs, game_object **sprite);

void restart_obstacles(list **gbl, l_list **obstacles, enum pages *state,
game_object ***sprite);

#endif /* MYRUNNER_H_ */