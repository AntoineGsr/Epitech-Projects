/*
** EPITECH PROJECT, 2020
** my_defender.h
** File description:
** my_defender
*/

#ifndef MYDEFENDER_H_
#define MYDEFENDER_H_

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
    PRESENTATION,
    PSEUDO,
    MENU,
    START,
    MORE,
    SAVE,
    ACHIEVEMENT,
    RAVEN,
    RAVEN_CLICK,
    RAVEN_ELEC,
    MOVE_MORE,
    MENU_MORE,
    PUZZLE,
    MINI_GAMES,
    SURVIVAL,
    VS,
    OPTIONS,
    HELP,
    BACK,
    MOVE_MENU,
    PUZZLE_CLICK,
    PUZZLE_OK,
    MINI_GAMES_CLICK,
    PLANT_CHOSE,
    ZOMBIE_CHOSE,
    PLANT_CHOSE_CLICK,
    ZOMBIE_CHOSE_CLICK,
    SUN_FLOWER_PRESENT,
    GREEN_FLOWER_PRESENT,
    BLUE_FLOWER_PRESENT,
    CARNIVORE_FLOWER_PRESENT,
    MINE_FLOWER_PRESENT,
    PLANT_EXIT,
    ZOMBIE_EXIT,
    MINI_GAMES_OK,
    OPTIONS_CLICK,
    OPTIONS_MUSIC,
    OPTIONS_SOUND,
    OPTIONS_OK,
    VS_CLICK,
    VS_OK,
    SURVIVAL_CLICK,
    SURVIVAL_OK,
    HELP_CLICK,
    HELP_OK,
    MOVE_CLOUD,
    MOVE_GAME,
    TUTO1,
    TUTO2,
    TUTO3,
    TUTO4,
    ENTITY_CREATION,
    GAME,
    GAME_MENU,
    CARD_SUN,
    CARD_SHOOTER,
    CARD_CARNIVOR,
    CARD_BOMB,
    CARD_OBSTACLE,
    CARD_FROZ,
    CARD_SUN_CLICK,
    CARD_SHOOTER_CLICK,
    CARD_CARNIVOR_CLICK,
    CARD_BOMB_CLICK,
    CARD_OBSTACLE_CLICK,
    CARD_FROZ_CLICK,
    CARD_SUN_RELEASED,
    CARD_SHOOTER_RELEASED,
    CARD_CARNIVOR_RELEASED,
    CARD_BOMB_RELEASED,
    CARD_OBSTACLE_RELEASED,
    CARD_FROZ_RELEASED,
    CLICK_INGAME,
    GAME_MENU_CLICK,
    GAME_MENU_MENU,
    GAME_MENU_MENU_CLICK,
    GAME_MENU_RESUME,
    GAME_MENU_RESUME_CLICK,
    GAME_MENU_QUIT,
    GAME_MENU_QUIT_CLICK,
    QUIT,
    MOVE_BACK_GAME,
    DESTROY_ENTITY,
    MOVE_BACK_MENU,
};

l_list *add_first(list **gbl, l_list **node, int nb);
l_list *add_to_list(list **gbl, l_list **node, int i, int j);
list *create_global_list(game_object **sprite);
void del_to_list(list **gbl, l_list **node, int pos);
void del_last_first(list **gbl, l_list **node);
void destroy_list(list **gbl, l_list **node);
void destroy_first_node(list **gbl, l_list **node);
void destroy_node_noloop(list **gbl, l_list **node, int *pos);
char *display(l_list *node);
l_list *add_to_list_zombie(list **gbl, l_list **node, int random);
l_list *add_to_list_plante(list **gbl, l_list **node, int type_plante);
void destroy_all(game_object ***sprite, list ***gbl, l_list ***node,
sfRenderWindow *window);
void loop_map_game(list **gbl);

sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
game_object *create_object(const char *fl_path, sfVector2f pos, sfIntRect rect);
void analyse_events(sfRenderWindow *window, sfEvent event,
game_object ***sprite, enum pages *state);
void gestion_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window, list **gbl);
void gestion_music(game_object **sprite, enum pages *state);
void display_sprite(game_object **sprite, sfRenderWindow *window, int i,
int max);
int display_game(list ***gbl, l_list ***node, enum pages *state,
sfRenderWindow *window);
void use_sound_effect(game_object **mob);
void display_sun_wallet(char *str, sfColor color, sfRenderWindow *window,
sfVector2f vect);
void display_text(list ***gbl, l_list ***node, sfRenderWindow *window,
enum pages *state);
void game_lost(list ***gbl, game_object ***sprite, enum pages *state);

void create_objects_menu(game_object ***sprite);
void create_objects_game(game_object ***sprite);
void create_all_objects(game_object ***sprite);
void modif_money_price(game_object ***sprite);
void create_lists(list ***gbl, l_list ***node, game_object **sprite);

void manage_key_pressed(sfEvent event, enum pages *state);
void manage_mouse_move(sfEvent event, enum pages *state, game_object ***sprite);
void manage_mouse_click(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite);
void manage_mouse_released(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite);

void menu_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window);
void mouse_move_menu(sfEvent event, enum pages *state);
void mouse_move_menu_more(sfEvent event, enum pages *state);
void mouse_click_game(enum pages *state, game_object ***sprite,
sfRenderWindow *window, sfEvent event);
void puzzle_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display);
void mini_games_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display);
void mini_games_choose_plant(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display);
void options_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display);
void vs_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display);
void survival_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display);
void help_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display);
void move_menu_more_game(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display);
void print_player_name_ingame(game_object ***sprite, enum pages *state,
sfRenderWindow *window);
void state_sprite_first_menu(game_object ***sprite, enum pages *state,
sfRenderWindow *window);
void state_sprite_second_menu(game_object ***sprite, enum pages *state,
sfRenderWindow *window);
void raven_animation(game_object ***sprite, enum pages *state,
sfRenderWindow *window);
void refresh_sprite_index(game_object ***sprite, int i, char *pth_one,
char *pth_two);
void game_card_plants(game_object ***sprite, enum pages *state,
int *max_display);
void move_game_menu(game_object ***sprite, enum pages *state,
sfRenderWindow *window);

void mouse_move_puzzle_click(sfEvent event, enum pages *state);
void mouse_move_minigames_click(sfEvent event, enum pages *state);
void mouse_move_options_click(sfEvent event, enum pages *state);
void mouse_move_vs_click(sfEvent event, enum pages *state);
void mouse_move_survival_click(sfEvent event, enum pages *state);
void mouse_move_help_click(sfEvent event, enum pages *state);
void mouse_move_pause(sfEvent event, enum pages *state,
game_object ***sprite);

void presentation_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window);
void pseudo_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window);
void input_name_init(game_object **sprite, sfColor color,
sfRenderWindow *window, sfVector2f vect);
void input_name_handling(game_object ***sprite, enum pages *state,
sfRenderWindow *window, sfEvent event);

void tuto_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window);
void game_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window);

void entity_gestion(list ***gbl, l_list ***node, game_object ***sprite,
enum pages *state);
void print_player_name(game_object ***sprite, enum pages *state,
sfRenderWindow *window);

void mouse_move_game(sfEvent event, enum pages *state, game_object ***sprite);

void create_music(const char *fl_path, game_object **mob);
void create_sound(const char *fl_path, game_object **mob);

l_list *add_to_list_bullet(list **gbl, l_list ***node);
game_object *create_object_bullet(list **gbl, int type_plante,
sfVector2f posit);

int build_plante(list ***gbl, l_list ***node, game_object ***sprite);
int center_plante(list ***gbl, l_list ***node, game_object ***sprite,
float center);
void analyse_action(list ***gbl, l_list ***node, game_object ***sprite);
void pause_gestion(list ***gbl, l_list ***node);
void lvl_up_plante(list ***gbl, l_list ***node, game_object ***sprite,
enum pages *state);
void zombie_movement(list ***gbl, l_list ***node, game_object ***sprite);
void animation_plante(list ***gbl, l_list ***node, game_object ***sprite);
void projectils_movement(list ***gbl, l_list ***node, game_object ***sprite);
void plante_one(list **gbl, game_object **mob);
void plante_two(list **gbl, game_object **mob);
void plante_three(list **gbl, game_object **mob);
void plante_foor(list **gbl, game_object **mob);
void plante_five(list **gbl, game_object **mob);

void get_seed(void);

#endif /* MYDEFENDER_H_ */