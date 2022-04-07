/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../include/my.h"

void call_func(rpg_t *rpg_tab)
{
    if (rpg_tab->step == MENU)
        handle_menu(rpg_tab);
    if (rpg_tab->step == PARAM)
        menu_param(rpg_tab);
    if (rpg_tab->step == HELP)
        menu_help(rpg_tab);
    if (rpg_tab->step == GAME)
        game(rpg_tab);
    if (rpg_tab->step == LOAD)
        menu_load(rpg_tab);
    if (rpg_tab->step == GAME_PARAM)
        game_param(rpg_tab);
    if (rpg_tab->step == END_GAME)
        end_menu(rpg_tab);
    if (rpg_tab->step == SKIN)
        menu_skin(rpg_tab);
}

void game_loop(rpg_t *rpg_tab)
{
    while (sfRenderWindow_isOpen(rpg_tab->window) && rpg_tab->step != END) {
        handle_coeff(rpg_tab);
        call_func(rpg_tab);
        handle_cursor(rpg_tab);
        handle_transition(rpg_tab);
        icon_handling(rpg_tab);
        sfRenderWindow_display(rpg_tab->window);
    }
    if (rpg_tab->g->link_start_state >= LOG_DONE)
        create_new_save(rpg_tab);
    create_new_config(rpg_tab);
}