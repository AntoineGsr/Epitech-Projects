/*
** EPITECH PROJECT, 2021
** gm_display_three.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void gd_eleven_one(rpg_t *rpg_tab)
{
    sfText_setPosition(rpg_tab->g->mehdik_txt[0]->text,
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){600, 860}, rpg_tab->view));
    sfRenderWindow_drawText(rpg_tab->window,
    rpg_tab->g->mehdik_txt[0]->text, NULL);
    sfText_setPosition(rpg_tab->g->mehdik_txt[1]->text,
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){200, 920}, rpg_tab->view));
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
    mehdik_txt[1]->text, NULL);
}

void gd_eleven_two(rpg_t *rpg_tab)
{
    sfText_setPosition(rpg_tab->g->mehdik_txt[2]->text,
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){500, 860}, rpg_tab->view));
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
    mehdik_txt[2]->text, NULL);
    sfText_setPosition(rpg_tab->g->mehdik_txt[3]->text,
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){700, 920}, rpg_tab->view));
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->
    mehdik_txt[3]->text, NULL);
}

void gd_eleven(rpg_t *rpg_tab)
{
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->player_info->
    gun_icon->sprite, NULL);
    rpg_tab->g->seconds_medhik = sfClock_getElapsedTime(
    rpg_tab->g->clock_medhik).microseconds / 1000000.0;
    if (rpg_tab->g->talk_mehdik == true) {
        if (rpg_tab->g->seconds_medhik < 5 && rpg_tab->g->
        mehdik_quest_done == false) {
            gd_eleven_one(rpg_tab);
        } else if (rpg_tab->g->seconds_medhik < 5 && rpg_tab->g->
        mehdik_quest_done == true) {
            gd_eleven_two(rpg_tab);
        } else {
            rpg_tab->g->talk_mehdik = false;
        }
    }
}