/*
** EPITECH PROJECT, 2020
** display_my_window.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

sfVector2f init_text_score(sfFont **font, sfText **text, sfVector2f pos_txt)
{
    pos_txt.x = 910;
    pos_txt.y = 10;
    *font = sfFont_createFromFile("./src/arial.ttf");
    *text = sfText_create();
    sfText_setFont(*text, *font);
    sfText_setCharacterSize(*text, 50);
    sfText_setPosition(*text, pos_txt);
    return (pos_txt);
}

void luffy_life(S_base *life, char const *filepath, int nb_life,
sfRenderWindow *window)
{
    life->texture = sfTexture_createFromFile(filepath, NULL);
    life->sprite = sfSprite_create();
    life->sprite_copy = sfSprite_copy(life->sprite);
    life->rect.top = 110 * nb_life;
    life->rect.left = 0;
    life->rect.width = 300;
    life->rect.height = 110;
    life->pos.x = 810;
    life->pos.y = 920;
    sfSprite_setTexture(life->sprite, life->texture, sfTrue);
    sfSprite_setTextureRect(life->sprite, life->rect);
    sfSprite_setPosition(life->sprite, life->pos);
    sfRenderWindow_drawSprite(window, life->sprite, NULL);
}

void draw_clone(sfRenderWindow *window, S_base *bird, int i)
{
    if (bird[i].pos.y >= 940 && bird[i].offset == bird[i].max_value) {
        sfSprite_setTextureRect(bird[i].sprite_copy, bird[i].rect);
        sfRenderWindow_drawSprite(window, bird[i].sprite_copy, NULL);
    } else
        sfRenderWindow_drawSprite(window, bird[i].sprite_copy, NULL);
}

void display_my_window(sfRenderWindow *window, B_base *bck, S_base *bird,
sfTime time)
{
    int score = 0;
    sfFont *font;
    sfText *text;
    sfVector2f pos_txt = init_text_score(&font, &text, pos_txt);
    S_base life;
    float seconds = time.microseconds / 1000000.0;

    sfRenderWindow_drawSprite(window, bck->sprite, NULL);
    for (int i = 0; i < bird[i].nb_bird; i++) {
        score += bird[i].score;
        sfText_setString(text, my_getstr(score));
        sfSprite_setTextureRect(bird[i].sprite, bird[i].rect);
        sfRenderWindow_drawSprite(window, bird[i].sprite, NULL);
        restart_sprite(bird, window, i, seconds);
        draw_clone(window, bird, i);
    }
    luffy_life(&life, "./src/lify.png", bird->life, window);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    sfText_destroy(text);
}
