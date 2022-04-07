/*
** EPITECH PROJECT, 2020
** game_page.c
** File description:
** my_runner
*/

#include "my_runner.h"

void display_game(sfRenderWindow *window, game_object **sprite, sfText *text,
sfText *text_hs)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < 8; i++) {
        parallax_effect(&sprite[i], &sprite[i + 8], i);
        sfSprite_setTexture(sprite[i]->sprite, sprite[i]->texture, sfTrue);
        sfSprite_setPosition(sprite[i]->sprite, sprite[i]->pos);
        sfRenderWindow_drawSprite(window, sprite[i]->sprite, NULL);
        sfSprite_setTexture(sprite[i + 8]->sprite, sprite[i + 8]->texture,
        sfTrue);
        sfSprite_setPosition(sprite[i + 8]->sprite, sprite[i + 8]->pos);
        sfRenderWindow_drawSprite(window, sprite[i + 8]->sprite, NULL);
    }
    sfSprite_setTexture(sprite[16]->sprite, sprite[16]->texture, sfTrue);
    sfSprite_setTextureRect(sprite[16]->sprite, sprite[16]->rect);
    sfSprite_setPosition(sprite[16]->sprite, sprite[16]->pos);
    sfRenderWindow_drawSprite(window, sprite[16]->sprite, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_drawText(window, text_hs, NULL);
}

void game_page(game_object **sprite, enum pages *state, sfRenderWindow *window,
list **gbl)
{
    sfFont *font;
    sfText *text;
    sfVector2f pos_txt = (sfVector2f){15, 40};
    sfFont *font_hs;
    sfText *text_hs;
    sfVector2f pos_txt_hs = (sfVector2f){22, 5};

    animate_character(sprite);
    update_score(&font, &text, pos_txt, my_getstr(sprite[16]->case_map));
    update_high_score(&font_hs, &text_hs, pos_txt_hs, sprite);
    display_game(window, sprite, text, text_hs);
    sprite[16]->case_map += 1;
    (*gbl)->speed = sprite[7]->speed_parallax - 6;
    if (sprite[16]->life == 0)
        *state = 18;
    sfFont_destroy(font);
    sfText_destroy(text);
}