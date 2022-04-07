/*
** EPITECH PROJECT, 2021
** game_gestion.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void verif_price_card(game_object **sprite, int sun_wallet, int price)
{
    if (sun_wallet < price) {
        if ((*sprite)->rect.left == 0)
            (*sprite)->rect.left += (*sprite)->rect.width;
    } else
        (*sprite)->rect.left = 0;
}

void reload_sprite_game(game_object ***sprite, enum pages *state)
{
    sfTexture_destroy((*sprite)[8]->texture);
    (*sprite)[8]->texture = sfTexture_createFromFile("./images/game.png",
    NULL);
    sfTexture_destroy((*sprite)[9]->texture);
    (*sprite)[9]->texture = sfTexture_createFromFile
    ("./images/menu_button.png", NULL);
    sfTexture_destroy((*sprite)[16]->texture);
    (*sprite)[16]->texture = sfTexture_createFromFile
    ("./images/pause_menu.png", NULL);
    sfTexture_destroy((*sprite)[17]->texture);
    (*sprite)[17]->texture = sfTexture_createFromFile
    ("./images/pause_resume.png", NULL);
    sfTexture_destroy((*sprite)[18]->texture);
    (*sprite)[18]->texture = sfTexture_createFromFile
    ("./images/pause_quit.png", NULL);
}

void game_menu_first(game_object ***sprite, enum pages *state)
{
    if (*state == GAME_MENU_MENU) {
        sfTexture_destroy((*sprite)[16]->texture);
        (*sprite)[16]->texture = sfTexture_createFromFile
        ("./images/pause_menu_move.png", NULL);
    }
    if (*state == GAME_MENU_MENU_CLICK) {
        sfTexture_destroy((*sprite)[16]->texture);
        (*sprite)[16]->texture = sfTexture_createFromFile
        ("./images/pause_menu_click.png", NULL);
    }
    if (*state == GAME_MENU_RESUME) {
        sfTexture_destroy((*sprite)[17]->texture);
        (*sprite)[17]->texture = sfTexture_createFromFile
        ("./images/pause_resume_move.png", NULL);
    }
    if (*state == GAME_MENU_RESUME_CLICK) {
        sfTexture_destroy((*sprite)[17]->texture);
        (*sprite)[17]->texture = sfTexture_createFromFile
        ("./images/pause_resume_click.png", NULL);
    }
}

void game_menu_second(game_object ***sprite, enum pages *state)
{
    if (*state == GAME_MENU_QUIT) {
        sfTexture_destroy((*sprite)[18]->texture);
        (*sprite)[18]->texture = sfTexture_createFromFile
        ("./images/pause_quit_move.png", NULL);
    }
    if (*state == GAME_MENU_QUIT_CLICK) {
        sfTexture_destroy((*sprite)[18]->texture);
        (*sprite)[18]->texture = sfTexture_createFromFile
        ("./images/pause_quit_click.png", NULL);
    }
}

void game_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    int max_display = 15;

    for (int i = 10; i < 15; i++)
        verif_price_card(&(*sprite)[i], (*sprite)[0]->sun_wallet,
        (*sprite)[i]->price);
    reload_sprite_game(sprite, state);
    if (*state == GAME_MENU)
        refresh_sprite_index(sprite, 9, "./images/menu_button_ok.png",
        "./images/menu_button_released.png");
    game_card_plants(sprite, state, &max_display);
    game_menu_first(sprite, state);
    game_menu_second(sprite, state);
    display_sprite(*sprite, window, 8, 16);
    display_sprite(*sprite, window, 19, 20);
    if (*state >= GAME_MENU_CLICK)
        display_sprite(*sprite, window, 16, 19);
    if (max_display > 15)
        display_sprite(*sprite, window, 20, 21);
    if (*state >= MOVE_BACK_GAME)
        move_game_menu(sprite, state, window);
}