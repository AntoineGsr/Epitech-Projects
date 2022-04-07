/*
** EPITECH PROJECT, 2021
** gm_display_three.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void gd_fort(rpg_t *rpg_tab, float seconds)
{
    if (seconds >= 22 && seconds < 28) {
        sfText_setPosition(rpg_tab->g->start_msg[6]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){300, 880}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
        start_msg[6]->text, NULL);
        sfText_setPosition(rpg_tab->g->start_msg[7]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){600, 930}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
        start_msg[7]->text, NULL);
    }
    if (seconds >= 28 && seconds < 32) {
        sfText_setPosition(rpg_tab->g->start_msg[8]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){150, 900}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
        start_msg[8]->text, NULL);
    }
}

void gd_thirt(rpg_t *rpg_tab, float seconds)
{
    if (seconds >= 16 && seconds < 22) {
        sfText_setPosition(rpg_tab->g->start_msg[4]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){100, 880}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
        start_msg[4]->text, NULL);
        sfText_setPosition(rpg_tab->g->start_msg[5]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){600, 930}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
        start_msg[5]->text, NULL);
    }
}

void gd_twelve(rpg_t *rpg_tab, float seconds)
{
    if (seconds > 7 && seconds < 12) {
        sfText_setPosition(rpg_tab->g->start_msg[3]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){350, 900}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
        start_msg[3]->text, NULL);
    }
    if (seconds >= 12 && seconds < 16) {
        sfText_setPosition(rpg_tab->g->start_msg[4]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){100, 880}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
        start_msg[4]->text, NULL);
        sfText_setPosition(rpg_tab->g->start_msg[5]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){600, 930}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
        start_msg[5]->text, NULL);
    }
}