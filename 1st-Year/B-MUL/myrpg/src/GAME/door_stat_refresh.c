/*
** EPITECH PROJECT, 2021
** door_stat_refresh.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void door_refr_win(rpg_t *rpg_tab)
{
    rpg_tab->g->card->big_card->sprite_pos =
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){coeff_window(rpg_tab->window_size.x, 450, 1920),
    coeff_window(rpg_tab->window_size.y, 335, 1080)}, rpg_tab->view);
    rpg_tab->g->card->scanner->sprite_pos =
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){coeff_window(rpg_tab->window_size.x, 1000, 1920),
    coeff_window(rpg_tab->window_size.y, 300, 1080)}, rpg_tab->view);
    rpg_tab->g->card->code_door_two->text_pos =
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){coeff_window(rpg_tab->window_size.x, 900, 1920),
    coeff_window(rpg_tab->window_size.y, 90, 1080)}, rpg_tab->view);
    rpg_tab->g->card->display_digit->sprite_pos =
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){coeff_window(rpg_tab->window_size.x, 724, 1920),
    coeff_window(rpg_tab->window_size.y, 28, 1080)}, rpg_tab->view);
}

void door_refr_loops(rpg_t *rpg_tab)
{
    for (int i = 0; i < 3; i++) {
        rpg_tab->g->card->digit_number[i]->sprite_pos =
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){coeff_window(rpg_tab->window_size.x, 724 + 168 * i, 1920),
        coeff_window(rpg_tab->window_size.y, 293, 1080)}, rpg_tab->view);
    }
    for (int i = 3; i < 6; i++) {
        rpg_tab->g->card->digit_number[i]->sprite_pos =
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){coeff_window(rpg_tab->window_size.x,
        724 + 168 * (i - 3), 1920),
        coeff_window(rpg_tab->window_size.y, 461, 1080)}, rpg_tab->view);
    }
    for (int i = 6; i < 9; i++) {
        rpg_tab->g->card->digit_number[i]->sprite_pos =
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){coeff_window(rpg_tab->window_size.x,
        724 + 168 * (i - 6), 1920),
        coeff_window(rpg_tab->window_size.y, 629, 1080)}, rpg_tab->view);
    }
}

void door_refr_pos(rpg_t *rpg_tab)
{
    rpg_tab->g->card->scanner->sprite_frect = (sfFloatRect)
    {rpg_tab->g->card->scanner->sprite_pos.x,
    rpg_tab->g->card->scanner->sprite_pos.y,
    rpg_tab->g->card->scanner->sprite_rect.width,
    rpg_tab->g->card->scanner->sprite_rect.height};
    rpg_tab->g->card->big_card->sprite_frect = (sfFloatRect)
    {rpg_tab->g->card->big_card->sprite_pos.x
    + coeff_window(rpg_tab->window_size.x, 50, 1920),
    rpg_tab->g->card->big_card->sprite_pos.y, 50, 100};
    rpg_tab->g->card->click_hitbox_big_card = (sfFloatRect)
    {rpg_tab->g->card->big_card->sprite_pos.x,
    rpg_tab->g->card->big_card->sprite_pos.y,
    rpg_tab->g->card->big_card->sprite_rect.width,
    rpg_tab->g->card->big_card->sprite_rect.height};
    sfSprite_setPosition(rpg_tab->g->card->big_card->sprite,
    rpg_tab->g->card->big_card->sprite_pos);
    sfSprite_setPosition(rpg_tab->g->card->scanner->sprite,
    rpg_tab->g->card->scanner->sprite_pos);
}

void game_stat_refresh_door(rpg_t *rpg_tab)
{
    if (rpg_tab->g->open_door == false) {
        door_refr_win(rpg_tab);
        door_refr_loops(rpg_tab);
    }
    for (int i = 0; i < 9; i++) {
        rpg_tab->g->card->digit_number[i]->sprite_frect = (sfFloatRect)
        {rpg_tab->g->card->digit_number[i]->sprite_pos.x,
        rpg_tab->g->card->digit_number[i]->sprite_pos.y,
        rpg_tab->g->card->digit_number[i]->sprite_rect.width,
        rpg_tab->g->card->digit_number[i]->sprite_rect.height};
    }
    door_refr_pos(rpg_tab);
}