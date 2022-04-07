/*
** EPITECH PROJECT, 2021
** pause_page.c
** File description:
** my_runner
*/

#include "my_runner.h"

void display_button(game_object *button, sfRenderWindow *window)
{
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, button->pos);
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
}

void display_pause_menu(game_object **sprite, game_object *pause,
enum pages state, sfRenderWindow *window)
{
    if (state >= PAUSE_CLICK) {
        for (int i = 0; i < 8; i++) {
            sfSprite_setTexture(sprite[i]->sprite, sprite[i]->texture, sfTrue);
            sfSprite_setPosition(sprite[i]->sprite, sprite[i]->pos);
            sfRenderWindow_drawSprite(window, sprite[i]->sprite, NULL);
            sfSprite_setTexture(sprite[i + 8]->sprite, sprite[i + 8]->texture,
            sfTrue);
            sfSprite_setPosition(sprite[i + 8]->sprite, sprite[i + 8]->pos);
            sfRenderWindow_drawSprite(window, sprite[i + 8]->sprite, NULL);
        }
        sfSprite_setTexture(pause->sprite, pause->texture, sfTrue);
        sfSprite_setTextureRect(pause->sprite, pause->rect);
        sfSprite_setPosition(pause->sprite, pause->pos);
        sfRenderWindow_drawSprite(window, pause->sprite, NULL);
    }
}

void gestion_sprite_pause_state(enum pages state, game_object *button_pause,
game_object *pause)
{
    if (state == PAUSE)
        button_pause->texture = sfTexture_createFromFile
        ("./image/button_pause_red.png", NULL);
    if (state == RESUME)
        pause->texture = sfTexture_createFromFile
        ("./image/resume_red.png", NULL);
    if (state == RESTART)
        pause->texture = sfTexture_createFromFile
        ("./image/restart_red.png", NULL);
    if (state == SOUND_EFFECT)
        pause->texture = sfTexture_createFromFile
        ("./image/sound_effect_red.png", NULL);
    if (state == MUSIC)
        pause->texture = sfTexture_createFromFile
        ("./image/music_red.png", NULL);
    if (state == EXIT)
        pause->texture = sfTexture_createFromFile
        ("./image/exit_red.png", NULL);
}

void gestion_sprite_home_state(enum pages state, game_object *home_button)
{
    if (state == HOME) {
        home_button->texture = sfTexture_createFromFile
        ("./image/home_red.png", NULL);
    }
}

void home_pause_page(game_object **sprite, enum pages state,
sfRenderWindow *window)
{
    game_object *button_pause = create_object("./image/button_pause.png",
    (sfVector2f){1850, 20}, (sfIntRect){0, 0, 50, 50});
    game_object *pause = create_object("./image/pause.png",
    (sfVector2f){660, 115}, (sfIntRect){0, 0, 600, 851});
    game_object *button_home = create_object("./image/home.png",
    (sfVector2f){1790, 20}, (sfIntRect){0, 0, 50, 50});

    gestion_sprite_pause_state(state, button_pause, pause);
    gestion_sprite_home_state(state, button_home);
    display_button(button_pause, window);
    display_button(button_home, window);
    display_pause_menu(sprite, pause, state, window);
    destroy_object(button_pause);
    destroy_object(pause);
    destroy_object(button_home);
}