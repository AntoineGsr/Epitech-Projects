/*
** EPITECH PROJECT, 2021
** manage_mouse_button_released.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void released_first_menu(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite)
{
    if (*state == START) {
        sfClock_restart((*sprite)[2]->clock);
        *state = MOVE_CLOUD;
    }
    if (*state == MORE) {
        sfClock_restart((*sprite)[2]->clock);
        *state = MOVE_MORE;
    }
    if (*state == RAVEN) {
        *state = RAVEN_CLICK;
    }
}

void released_mini_games_window(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite)
{
    if (*state == PLANT_CHOSE)
        *state = PLANT_CHOSE_CLICK;
    if (*state == ZOMBIE_CHOSE)
        *state = PLANT_CHOSE_CLICK;
    if (*state == PLANT_EXIT || *state == ZOMBIE_EXIT)
        *state = MINI_GAMES_CLICK;
}

void released_more_menu(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite)
{
    if (*state == BACK) {
        sfClock_restart((*sprite)[2]->clock);
        *state = MOVE_MENU;
    }
    if (*state == PUZZLE)
        *state = PUZZLE_CLICK;
    if (*state == MINI_GAMES)
        *state = MINI_GAMES_CLICK;
    released_mini_games_window(event, window, state, sprite);
    if (*state == OPTIONS)
        *state = OPTIONS_CLICK;
    if (*state == HELP)
        *state = HELP_CLICK;
    if (*state == SURVIVAL)
        *state = SURVIVAL_CLICK;
    if (*state == VS)
        *state = VS_CLICK;
    if (*state == PUZZLE_OK || *state == OPTIONS_OK || *state == SURVIVAL_OK
        || *state == VS_OK || *state == HELP_OK || *state == MINI_GAMES_OK)
        *state = MENU_MORE;
}

void released_ingame(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite)
{
    if  (*state == GAME_MENU)
        *state = GAME_MENU_CLICK;
    if (*state == CARD_SUN_CLICK)
        *state = CARD_SUN_RELEASED;
    if (*state == CARD_SHOOTER_CLICK)
        *state = CARD_SHOOTER_RELEASED;
    if (*state == CARD_CARNIVOR_CLICK)
        *state = CARD_CARNIVOR_RELEASED;
    if (*state == CARD_BOMB_CLICK)
        *state = CARD_BOMB_RELEASED;
    if (*state == CARD_FROZ_CLICK)
        *state = CARD_FROZ_RELEASED;
    if (*state == CARD_OBSTACLE_CLICK)
        *state = CARD_OBSTACLE_RELEASED;
    if (*state == GAME_MENU_MENU_CLICK) {
        sfClock_restart((*sprite)[2]->clock);
        *state = MOVE_BACK_GAME;
    }
    if (*state == GAME_MENU_RESUME_CLICK)
        *state = GAME;
}

void manage_mouse_released(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite)
{
    if ((*sprite)[0]->mouse_left_click == 1) {
        (*sprite)[0]->mouse_left_click = 0;
    } else
        return;
    released_first_menu(event, window, state, sprite);
    released_more_menu(event, window, state, sprite);
    released_ingame(event, window, state, sprite);
    if (*state == GAME_MENU_QUIT_CLICK)
        *state = QUIT;
}