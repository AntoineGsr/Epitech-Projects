/*
** EPITECH PROJECT, 2021
** menu_page.c
** File description:
** my_runner
*/

#include "my_runner.h"

void display_menu(game_object **sprite, game_object *menu,
sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < 8; i++) {
        sfSprite_setTexture(sprite[i]->sprite, sprite[i]->texture, sfTrue);
        sfSprite_setPosition(sprite[i]->sprite, sprite[i]->pos);
        sfRenderWindow_drawSprite(window, sprite[i]->sprite, NULL);
    }
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfSprite_setPosition(menu->sprite, menu->pos);
    sfRenderWindow_drawSprite(window, menu->sprite, NULL);
}

void click_stgs_ctrl(game_object **sprite, enum pages state,
sfRenderWindow *window, game_object *menu)
{
    if (state == CTRL)
        menu->texture = sfTexture_createFromFile("./image/ctrl_clk.png", NULL);
    if (state == CTRL_BCK)
        menu->texture = sfTexture_createFromFile
        ("./image/controls_red.png", NULL);
    if (state == STGS)
        menu->texture = sfTexture_createFromFile("./image/stgs_clk.png", NULL);
    if (state == STGS_BCK)
        menu->texture = sfTexture_createFromFile
        ("./image/settings_red.png", NULL);
    if (state == STGS_8D)
        menu->texture = sfTexture_createFromFile
        ("./image/settings_8D_red.png", NULL);
    if (state == STGS_SOUND)
        menu->texture = sfTexture_createFromFile
        ("./image/settings_sound_red.png", NULL);
    if (state == STGS_MUSIC)
        menu->texture = sfTexture_createFromFile
        ("./image/settings_music_red.png", NULL);
}

void menu_page(game_object **sprite, enum pages state, sfRenderWindow *window)
{
    game_object *menu = create_object("./image/menu.png",
    (sfVector2f){660, 115}, (sfIntRect){0, 0, 600, 851});

    if (state == START)
        menu->texture = sfTexture_createFromFile("./image/start.png", NULL);
    if (state == CONTROLS)
        menu->texture = sfTexture_createFromFile("./image/controls.png", NULL);
    if (state == SETTINGS)
        menu->texture = sfTexture_createFromFile("./image/settings.png", NULL);
    if (state == QUIT)
        menu->texture = sfTexture_createFromFile("./image/quit.png", NULL);
    click_stgs_ctrl(sprite, state, window, menu);
    display_menu(sprite, menu, window);
    destroy_object(menu);
    restart_clocks(sprite);
}