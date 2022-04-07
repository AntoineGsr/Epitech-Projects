/*
** EPITECH PROJECT, 2021
** init_door_quest.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_door_quest_two(rpg_t *rpg_tab)
{
    rpg_tab->g->can_open_door = false;
    rpg_tab->g->open_door = false;
    rpg_tab->g->card->door_one = false;
    rpg_tab->g->card->door_two = false;
    for (int i = 0; i < 9; i++) {
        rpg_tab->g->card->digit_number[i] = malloc(sizeof(sprite_t));
        rpg_tab->g->card->digit_number[i] = get_my_sprite(rpg_tab, DIGIT,
        (sfVector2f){0, 0}, (sfIntRect){0, i * 164, 164, 164});
    }
    rpg_tab->g->card->display_digit = get_my_sprite(rpg_tab, PANNEL,
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 500, 245});
    rpg_tab->g->card->code_door_two = get_my_text("000", (sfVector2f){0, 0},
    sfWhite, 100);
    for (int i = 0; i < 4; i++)
        rpg_tab->g->card->code_door_two->ctrl[i] = '\0';
    rpg_tab->g->load = false;
}

void init_door_quest(rpg_t *rpg_tab)
{
    rpg_tab->g->card->click_hitbox_big_card = (sfFloatRect)
    {rpg_tab->g->card->big_card->sprite_pos.x,
    rpg_tab->g->card->big_card->sprite_pos.y,
    rpg_tab->g->card->big_card->sprite_rect.width,
    rpg_tab->g->card->big_card->sprite_rect.height};
    rpg_tab->g->card->big_card->sprite_frect = (sfFloatRect)
    {rpg_tab->g->card->big_card->sprite_pos.x
    + coeff_window(rpg_tab->window_size.x, 50, 1920),
    rpg_tab->g->card->big_card->sprite_pos.y, 50, 100};
    rpg_tab->g->card->scanner->sprite_frect = (sfFloatRect)
    {rpg_tab->g->card->scanner->sprite_pos.x,
    rpg_tab->g->card->scanner->sprite_pos.y,
    rpg_tab->g->card->scanner->sprite_rect.width,
    rpg_tab->g->card->scanner->sprite_rect.height};
    rpg_tab->g->card->access_card_mission = false;
    init_door_quest_two(rpg_tab);
}