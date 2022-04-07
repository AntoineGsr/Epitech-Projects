/*
** EPITECH PROJECT, 2020
** menu_page.c
** File description:
** my_runner
*/

#include "my_runner.h"

void moving_sprite_jump(game_object ***sprite)
{
    if ((*sprite)[18]->jump == 0)
        (*sprite)[18]->rect.top += 22;
    if ((*sprite)[18]->jump == 1)
        (*sprite)[18]->rect.top -= 22;
}

void animate_press(game_object ***sprite, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime((*sprite)[18]->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.07) {
        if ((*sprite)[18]->rect.top <= 0) {
            (*sprite)[18]->rect.top += 22;
            (*sprite)[18]->jump = 0;
        } else if ((*sprite)[18]->rect.top < 110) {
            moving_sprite_jump(sprite);
        }
        if ((*sprite)[18]->rect.top >= 110) {
            (*sprite)[18]->rect.top = 88;
            (*sprite)[18]->jump = 1;
        }
        sfClock_restart((*sprite)[18]->clock);
    }
}

void display_press(game_object **sprite, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTexture(sprite[17]->sprite, sprite[17]->texture, sfTrue);
    sfSprite_setTextureRect(sprite[17]->sprite, sprite[17]->rect);
    sfSprite_setPosition(sprite[17]->sprite, sprite[17]->pos);
    sfRenderWindow_drawSprite(window, sprite[17]->sprite, NULL);
    sfSprite_setTexture(sprite[18]->sprite, sprite[18]->texture, sfTrue);
    sfSprite_setTextureRect(sprite[18]->sprite, sprite[18]->rect);
    sfSprite_setPosition(sprite[18]->sprite, sprite[18]->pos);
    sfRenderWindow_drawSprite(window, sprite[18]->sprite, NULL);
}

void press_page(game_object **sprite, sfRenderWindow *window)
{
    animate_press(&sprite, window);
    display_press(sprite, window);
}