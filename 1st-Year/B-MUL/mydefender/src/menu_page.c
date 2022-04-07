/*
** EPITECH PROJECT, 2021
** sprite_page.c
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void display_sprite(game_object **sprite, sfRenderWindow *window, int i,
int max)
{
    if (i < max) {
        sfSprite_setTexture(sprite[i]->sprite, sprite[i]->texture, sfTrue);
        sfSprite_setTextureRect(sprite[i]->sprite, sprite[i]->rect);
        sfSprite_setPosition(sprite[i]->sprite, sprite[i]->pos);
        sfRenderWindow_drawSprite(window, sprite[i]->sprite, NULL);
        display_sprite(sprite, window, i += 1, max);
    }
    return;
}

void intercation_menu_more(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    puzzle_wind(sprite, state, window, max_display);
    mini_games_wind(sprite, state, window, max_display);
    options_wind(sprite, state, window, max_display);
    vs_wind(sprite, state, window, max_display);
    survival_wind(sprite, state, window, max_display);
    help_wind(sprite, state, window, max_display);
}

void menu_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    int max_display = 3;

    sfTexture_destroy((*sprite)[2]->texture);
    sfTexture_destroy((*sprite)[3]->texture);
    (*sprite)[2]->texture =
    sfTexture_createFromFile("./images/main_menu.jpg", NULL);
    (*sprite)[3]->texture =
    sfTexture_createFromFile("./images/falls_menu.png", NULL);
    state_sprite_first_menu(sprite, state, window);
    state_sprite_second_menu(sprite, state, window);
    intercation_menu_more(sprite, state, window, &max_display);
    move_menu_more_game(sprite, state, window, &max_display);
    raven_animation(sprite, state, window);
    display_sprite(*sprite, window, 2, max_display + 2);
    if (max_display == 4 && *state < MOVE_GAME)
        sfTexture_destroy((*sprite)[5]->texture);
    print_player_name_ingame(sprite, state, window);
}