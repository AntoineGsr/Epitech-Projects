/*
** EPITECH PROJECT, 2021
** gm_display.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void game_one(rpg_t *rpg_tab)
{
    sfText_setString(rpg_tab->g->log_wind->name->text,
    rpg_tab->g->log_wind->name->ctrl);
    sfText_setString(rpg_tab->g->log_wind->password->text,
    rpg_tab->g->log_wind->password->ctrl);
    sfRenderWindow_drawSprite(rpg_tab->window,
    rpg_tab->g->link_start_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(rpg_tab->window,
    rpg_tab->g->log_wind->wind->sprite, NULL);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->log_wind->
    name->text, NULL);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->log_wind->
    password->text, NULL);
    sfClock_restart(rpg_tab->g->perso->weapon_clock);
    sfClock_restart(rpg_tab->g->perso->guy->anim_clock);
}

void game_two(rpg_t *rpg_tab)
{
    for (int i = 0; i < rpg_tab->g->nb_mob; i++)
            sfClock_restart(rpg_tab->g->enemy[i]->blop->anim_clock);
    rpg_tab->g->perso->previous_clock =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
    rpg_tab->g->enemy[0]->previous_clock =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
    rpg_tab->g->enemy[0]->clock_move =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
    rpg_tab->g->gunshot_list->previous_clock =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
    sfClock_restart(rpg_tab->g->bidon->button->anim_clock);
    sfClock_restart(rpg_tab->g->clock_msg);
}

void game_three(rpg_t *rpg_tab, float seconds)
{
    if (seconds < 2) {
        sfText_setPosition(rpg_tab->g->start_msg[0]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){680, 530}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window,
        rpg_tab->g->start_msg[0]->text, NULL);
    }
    if (seconds >= 2 && seconds < 4) {
        sfText_setPosition(rpg_tab->g->start_msg[1]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){750, 530}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window,
        rpg_tab->g->start_msg[1]->text, NULL);
    }
}

void game_foor(rpg_t *rpg_tab, float seconds)
{
    if (seconds >= 4 && seconds < 6) {
        sfText_setString(rpg_tab->g->start_msg[2]->text,
        rpg_tab->g->start_msg[2]->ctrl);
        sfText_setPosition(rpg_tab->g->start_msg[2]->text,
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){720, 530}, rpg_tab->view));
        sfRenderWindow_drawText(rpg_tab->window,
        rpg_tab->g->start_msg[2]->text, NULL);
    }
    if (seconds >= 6)
        start_transition(rpg_tab);
    sfClock_restart(rpg_tab->g->perso->weapon_clock);
    sfClock_restart(rpg_tab->g->perso->guy->anim_clock);
    for (int i = 0; i < rpg_tab->g->nb_mob; i++)
        sfClock_restart(rpg_tab->g->enemy[i]->blop->anim_clock);
    rpg_tab->g->perso->previous_clock =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
}

void game_five(rpg_t *rpg_tab, float seconds)
{
    sfRenderWindow_clear(rpg_tab->window, sfBlack);
    game_three(rpg_tab, seconds);
    game_foor(rpg_tab, seconds);
    rpg_tab->g->enemy[0]->previous_clock =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
    rpg_tab->g->enemy[0]->clock_move =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
    rpg_tab->g->gunshot_list->previous_clock =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
    sfClock_restart(rpg_tab->g->bidon->button->anim_clock);
}
