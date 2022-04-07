/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_base(rpg_t *rpg_tab)
{
    malloc_struct(rpg_tab);
    init_config(rpg_tab);
    init_menu(rpg_tab);
    init_utils(rpg_tab);
    init_game(rpg_tab);
    init_keys(rpg_tab);
    init_min_map(rpg_tab);
    init_quest(rpg_tab);
    init_end_game(rpg_tab);
    init_particle(rpg_tab);
    init_icon(rpg_tab);
    rpg_tab->gbl_clock = sfClock_create();
}