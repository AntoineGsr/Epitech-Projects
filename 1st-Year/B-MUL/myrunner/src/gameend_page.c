/*
** EPITECH PROJECT, 2021
** gamewin_page.c
** File description:
** my_runner
*/

#include "my_runner.h"

void display_gameend(game_object **sprite, game_object *gameend,
enum pages *state, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(sprite[16]->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 2 || (*state >= GAMEWIN && *state <= W_END_QUIT)) {
        sfSprite_setTexture(gameend->sprite, gameend->texture, sfTrue);
        sfSprite_setTextureRect(gameend->sprite, gameend->rect);
        sfSprite_setPosition(gameend->sprite, gameend->pos);
        sfRenderWindow_drawSprite(window, gameend->sprite, NULL);
    }
}

void display_end_msg(game_object **sprite, game_object *end_msg,
sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < 8; i++) {
        sfSprite_setTexture(sprite[i]->sprite, sprite[i]->texture, sfTrue);
        sfSprite_setPosition(sprite[i]->sprite, sprite[i]->pos);
        sfRenderWindow_drawSprite(window, sprite[i]->sprite, NULL);
        sfSprite_setTexture(sprite[i + 8]->sprite, sprite[i + 8]->texture,
        sfTrue);
        sfSprite_setPosition(sprite[i + 8]->sprite, sprite[i + 8]->pos);
        sfRenderWindow_drawSprite(window, sprite[i + 8]->sprite, NULL);
    }
    sfSprite_setTexture(end_msg->sprite, end_msg->texture, sfTrue);
    sfSprite_setTextureRect(end_msg->sprite, end_msg->rect);
    sfSprite_setPosition(end_msg->sprite, end_msg->pos);
    sfRenderWindow_drawSprite(window, end_msg->sprite, NULL);
}

void gestion_sprite_endgame_state(game_object **sprite, enum pages *state,
game_object *gameend, sfRenderWindow *window)
{
    game_object *end_msg = NULL;

    if (*state >= GAMEWIN && *state <= W_END_QUIT)
        end_msg = create_object("./image/congrats.png", (sfVector2f){399, 10},
        (sfIntRect){0, 0, 1122, 304});
    if (*state >= GAMEOVER && *state <= L_END_QUIT)
        end_msg = create_object("./image/skull.png", (sfVector2f){0, 0},
        (sfIntRect){0, 0, 1920, 1080});
    if (*state == W_END_MENU || *state == L_END_MENU)
        gameend->texture = sfTexture_createFromFile
        ("./image/gameend_menu_red.png", NULL);
    if (*state == W_END_NEW_GAME || *state == L_END_NEW_GAME)
        gameend->texture = sfTexture_createFromFile
        ("./image/gameend_ngame_red.png", NULL);
    if (*state == W_END_QUIT || *state == L_END_QUIT)
        gameend->texture = sfTexture_createFromFile
        ("./image/gameover_quit_red.png", NULL);
    display_end_msg(sprite, end_msg, window);
    destroy_object(end_msg);
}

void gameend_page(game_object **sprite, enum pages *state,
sfRenderWindow *window)
{
    game_object *gameend = create_object("./image/gameend.png",
    (sfVector2f){660, 115}, (sfIntRect){0, 0, 600, 851});

    gestion_sprite_endgame_state(sprite, state, gameend, window);
    display_gameend(sprite, gameend, state, window);
    destroy_object(gameend);
}