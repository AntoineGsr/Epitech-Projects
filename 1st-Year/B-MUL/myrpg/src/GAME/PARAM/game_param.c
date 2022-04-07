/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../../include/my.h"

static void display_game_params(rpg_t *rpg_tab)
{
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->pause_game->sprite,
    NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(rpg_tab->window,
        rpg_tab->g->statistics[i]->text, NULL);
}

static void update_strings_params(rpg_t *rpg_tab)
{
    for (int i = 0; i < 3; i++) {
        free(rpg_tab->g->statistics[i]->ctrl);
        rpg_tab->g->statistics[i]->ctrl = my_memset_char(10);
    }
    rpg_tab->g->statistics[0]->ctrl = my_strcpy
    (rpg_tab->g->statistics[0]->ctrl, my_getstr(rpg_tab->g->var->cut_dmg));
    rpg_tab->g->statistics[1]->ctrl = my_strcpy
    (rpg_tab->g->statistics[1]->ctrl, my_getstr(rpg_tab->g->var->gun_dmg));
    rpg_tab->g->statistics[2]->ctrl = my_strcpy
    (rpg_tab->g->statistics[2]->ctrl, my_getstr(rpg_tab->g->perso->speed));
    for (int i = 0; i < 3; i++) {
        sfText_setString(rpg_tab->g->statistics[i]->text,
        rpg_tab->g->statistics[i]->ctrl);
    }
}

void pause_clock(rpg_t *rpg_tab)
{
    sfClock_restart(rpg_tab->g->perso->weapon_clock);
    sfClock_restart(rpg_tab->g->perso->guy->anim_clock);
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
}

void game_param_swh(rpg_t *rpg_tab)
{
    switch (rpg_tab->event.type) {
        case sfEvtKeyPressed:
            if (rpg_tab->event.key.code == rpg_tab->keys->game_menu)
                rpg_tab->step = GAME;
            return;
        default:
            return;
    }
}

void game_param(rpg_t *rpg_tab)
{
    background_defil_param(rpg_tab);
    pause_clock(rpg_tab);
    update_strings_params(rpg_tab);
    display_game_params(rpg_tab);
    while (sfRenderWindow_pollEvent(rpg_tab->window, &(rpg_tab->event))) {
        if (rpg_tab->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg_tab->window);
        game_param_swh(rpg_tab);
    }
}